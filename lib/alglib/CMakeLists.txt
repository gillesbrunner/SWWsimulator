cmake_minimum_required(VERSION 2.8)
project ( alglib )

set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SRC "src/*.cpp")
add_library(alglib SHARED ${SRC})
