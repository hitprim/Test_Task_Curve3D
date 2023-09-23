cmake_minimum_required(VERSION 3.26)
project(TestTask)

set(CMAKE_CXX_STANDARD 20)


add_executable(TestTask main.cpp
)

target_link_libraries(TestTask PRIVATE ${CMAKE_SOURCE_DIR}/bin/libCurves_3D.dll)
