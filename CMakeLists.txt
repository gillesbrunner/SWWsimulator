cmake_minimum_required( VERSION 2.8 )
project( SWWsimulator )

set(EXEC SWWsimulator)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -lz -ltiff")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 ${CMAKE_CXX_FLAGS}")

find_package( osg )
find_package( osgGA )
find_package( osgDB )
find_package( osgUtil )
find_package( osgViewer )

set( wxWidgets_CONFIGURATION mswu )
find_package( wxWidgets COMPONENTS gl core base REQUIRED )
include(${wxWidgets_USE_FILE})

# Precompiled headers
set(_header_filename "bin/precompiled")

function(get_gcc_flags target_name)
  # CMake does not provide an easy way to get all compiler switches,
  # so this function is a fishing expedition to get them.
  # http://public.kitware.com/Bug/view.php?id=1260
  if(CMAKE_CXX_COMPILER_ARG1)
      set(compile_args ${CMAKE_CXX_COMPILER_ARG1})
  else()
     set(compile_args "")
  endif()
  if(CMAKE_CXX_COMPILER_ARG2)
      list(APPEND compile_args ${CMAKE_CXX_COMPILER_ARG2})
  endif()
  list(APPEND compile_args ${CMAKE_CXX_FLAGS})
  string(TOUPPER "${CMAKE_BUILD_TYPE}" buildtype_name)
  if(CMAKE_CXX_FLAGS_${buildtype_name})
      list(APPEND compile_args ${CMAKE_CXX_FLAGS_${buildtype_name}})
  endif()
  get_directory_property(dir_inc INCLUDE_DIRECTORIES)
  foreach(item ${dir_inc})
    LIST(APPEND compile_args "-I" ${item})
  endforeach()
  get_directory_property(dir_defs COMPILE_DEFINITIONS)
  foreach(item ${dir_defs})
      list(APPEND compile_args -D${item})
  endforeach()
  get_directory_property(dir_buildtype_defs COMPILE_DEFINITIONS_${buildtype_name})
  foreach(item ${dir_buildtype_defs})
      list(APPEND compile_args -D${item})
  endforeach()
  get_directory_property(buildtype_defs COMPILE_DEFINITIONS_${buildtype_name})
  foreach(item ${buildtype_defs})
     list(APPEND compile_args -D${item})
  endforeach()
  get_target_property(target_type ${target_name} TYPE)
  if(${target_type} STREQUAL SHARED_LIBRARY)
    list(APPEND compile_args ${CMAKE_CXX_COMPILE_OPTIONS_PIC})
  endif()
  get_target_property(target_defs ${target_name} COMPILE_DEFINITIONS)
  if(target_defs)
    foreach(item ${target_defs})
      list(APPEND compile_args -D${item})
    endforeach()
  endif()
  get_target_property(target_buildtype_defs ${target_name} COMPILE_DEFINITIONS_${buildtype_name})
  if(target_buildtype_defs)
    foreach(item ${target_buildtype_defs})
      list(APPEND compile_args -D${item})
    endforeach()
  endif()
  get_target_property(target_flags ${target_name} COMPILE_FLAGS)
  if(target_flags)
      list(APPEND compile_args ${target_flags})
  endif()
  set(compile_args ${compile_args} PARENT_SCOPE)
  #message(STATUS ${compile_args})
endfunction()

function(add_pch_linux header_filename target_name pch_suffix)
  set(gch_target_name "${target_name}_pch")
  get_filename_component(header_basename ${header_filename} NAME)
  set(gch_filename "${CMAKE_CURRENT_BINARY_DIR}/${header_basename}.${pch_suffix}")
  get_gcc_flags(${target_name}) # Sets compile_args in this scope. It's even better than Intercal's COME FROM!
  #message(STATUS ${compile_args})
  list(APPEND compile_args -c ${CMAKE_CURRENT_SOURCE_DIR}/${header_filename} -o ${gch_filename})
  separate_arguments(compile_args)
  add_custom_command(OUTPUT ${gch_filename}
    COMMAND ${CMAKE_CXX_COMPILER} ${compile_args}
    DEPENDS ${header_filename})
  add_custom_target(${gch_target_name} DEPENDS ${gch_filename})
  add_dependencies(${target_name} ${gch_target_name})
  
  # Add the PCH to every source file's include list.
  # This is the only way that is supported by both GCC and Clang.
  set_property(TARGET ${target_name} APPEND_STRING PROPERTY COMPILE_FLAGS " -include ${header_basename} ")
  set_property(TARGET ${target_name} APPEND_STRING PROPERTY COMPILE_FLAGS " -fpch-preprocess ")
  set_property(TARGET ${target_name} APPEND_STRING PROPERTY COMPILE_FLAGS " -Winvalid-pch ")
  set_property(TARGET ${target_name} APPEND PROPERTY INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR})
  
endfunction()

if(UNIX)
	if(NOT APPLE)
		option(use_pch "Use precompiled headers." TRUE)
	endif()
endif()

if(use_pch)
	message(STATUS "Using precompiled headers.")
	if(IS_CLANG)
		set(precompiled_header_extension pch)
	else()
		set(precompiled_header_extension gch)
	endif()
	macro(add_pch _target_name _header_filename)
		add_pch_linux(${_header_filename} ${_target_name} ${precompiled_header_extension})
	endmacro()
else()
	message(STATUS "Not using precompiled headers.")
	macro(add_pch _target_name _header_filename)
	endmacro()
endif()

# Define ececutable
file(GLOB SRC "src/*.cpp" "src/*.h")
add_executable( ${EXEC} ${SRC})
add_pch(${EXEC} "src/included.h")

# Link the libraries
macro( config_project PROJNAME LIBNAME )
	include_directories( ${${LIBNAME}_INCLUDE_DIR} )
	target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()

set(libtiff_INCLUDE_DIR /usr/local/include)
set(libtiff_LIBRARY /usr/local/lib/libtiff.so)

set(libalglib_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/alglib/include)
set(libalglib_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/lib/alglib/build/libalglib.so)

config_project( ${EXEC} libtiff)
config_project( ${EXEC} libalglib)

config_project( ${EXEC} OSG )
config_project( ${EXEC} OSGGA )
config_project( ${EXEC} OSGDB )
config_project( ${EXEC} OSGUTIL )
config_project( ${EXEC} OSGVIEWER )


target_link_libraries( ${EXEC} ${wxWidgets_LIBRARIES} )
