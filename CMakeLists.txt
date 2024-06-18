cmake_minimum_required(VERSION 3.28)
project(mpdt)
# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) conan_basic_setup(TARGETS)
# set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
# set(CMAKE_EXE_LINKER_FLAGS "-lc++abi")

include(cmake/CPM.cmake)
# CPMAddPackage("https://gitee.com/n00333131/rapids-cmake.git#v23.02.00")
# CPMAddPackage("https://gitee.com/mirrors_NVIDIA/stdexec.git#nvhpc-23.09.rc4")

# find_package(stdexec)
# message(${stdexec_SOURCE_DIR})
# cpmaddpackage("https://gitee.com/pengybhnu/vsomeip.git#3.3.0")
# cpmaddpackage("https://gitee.com/pengybhnu/libcoro.git#v0.11.1")

project(mpd)
# add_library(roman) target_sources(roman PUBLIC FILE_SET cxx_modules TYPE
# CXX_MODULES FILES src/roman/M.cxx src/roman/interface_part.cxx
# src/roman/impl_part.cxx src/roman/implp.cxx

# )

# target_sources(roman PRIVATE src/roman/Impl.cpp )

add_library(stlm)
target_sources(stlm PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES
                           src/view/interface/stl.cppm)

add_library(infoview)
target_sources(
  infoview
  PUBLIC FILE_SET
         cxx_modules
         TYPE
         CXX_MODULES
         FILES
         src/view/interface/station.cppm
         src/view/interface/truck.cppm
         src/view/interface/view.cppm)
target_sources(infoview PRIVATE src/view/view.cpp src/view/truck.cpp
                                src/view/station.cpp)
target_link_libraries(infoview PRIVATE stlm)
add_library(mytest)
target_sources(mytest PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES
                             src/view/interface/test.cppm)
target_sources(mytest PUBLIC src/view/test.cpp)
target_link_libraries(mytest)

add_executable(dispatch)
target_sources(dispatch PRIVATE src/dispatch.cpp)
target_link_libraries(
  dispatch PRIVATE infoview stlm mytest
                   # CONAN_PKG::fmt
)

add_subdirectory(src)

# /opt/mapserver/.conan/data/cmake/3.28.1/_/_/package/4db1be536558d833e52e862fd84d64d75c2b3656/bin/cmake
# ..  -G Ninja -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang-16
# -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++-16 clang-17
