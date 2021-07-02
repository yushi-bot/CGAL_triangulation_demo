cmake_minimum_required(VERSION 3.1.0)
project(3Dtriangulation)

find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

add_executable(main "src/3dTriangulation.cpp")
