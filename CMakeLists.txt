cmake_minimum_required(VERSION 2.6)
project(algoritmos)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp merge.h binsearc.h arbolBin.h alvTree.h)

add_executable(algoritmos ${SOURCE_FILES})
install(TARGETS algoritmos RUNTIME DESTINATION bin)
