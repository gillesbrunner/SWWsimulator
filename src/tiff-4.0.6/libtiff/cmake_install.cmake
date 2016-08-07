# Install script for directory: /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib/libtiff.so.5.2.4"
      "$ENV{DESTDIR}/usr/local/lib/libtiff.so.5"
      "$ENV{DESTDIR}/usr/local/lib/libtiff.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libtiff.so.5.2.4;/usr/local/lib/libtiff.so.5;/usr/local/lib/libtiff.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/lib" TYPE SHARED_LIBRARY FILES
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/libtiff.so.5.2.4"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/libtiff.so.5"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/libtiff.so"
    )
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib/libtiff.so.5.2.4"
      "$ENV{DESTDIR}/usr/local/lib/libtiff.so.5"
      "$ENV{DESTDIR}/usr/local/lib/libtiff.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/tiff.h;/usr/local/include/tiffio.h;/usr/local/include/tiffvers.h;/usr/local/include/tiffconf.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/include" TYPE FILE FILES
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/tiff.h"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/tiffio.h"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/tiffvers.h"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/tiffconf.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib/libtiffxx.so.5.2.4"
      "$ENV{DESTDIR}/usr/local/lib/libtiffxx.so.5"
      "$ENV{DESTDIR}/usr/local/lib/libtiffxx.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libtiffxx.so.5.2.4;/usr/local/lib/libtiffxx.so.5;/usr/local/lib/libtiffxx.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/lib" TYPE SHARED_LIBRARY FILES
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/libtiffxx.so.5.2.4"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/libtiffxx.so.5"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/libtiffxx.so"
    )
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib/libtiffxx.so.5.2.4"
      "$ENV{DESTDIR}/usr/local/lib/libtiffxx.so.5"
      "$ENV{DESTDIR}/usr/local/lib/libtiffxx.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_REMOVE
           FILE "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/tiffio.hxx")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/include" TYPE FILE FILES "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/libtiff/tiffio.hxx")
endif()

