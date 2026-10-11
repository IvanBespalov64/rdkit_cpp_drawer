cmake_minimum_required(VERSION 3.18)
project(TestRDKit CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)   

find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED IMPORTED_TARGET cairo)

if(NOT TARGET Cairo::Cairo)
  add_library(Cairo::Cairo INTERFACE IMPORTED)
  target_link_libraries(Cairo::Cairo INTERFACE PkgConfig::CAIRO)
endif()

find_package(RDKit REQUIRED)

add_executable(svg_drawer svg_drawer.cpp)

target_link_libraries(
    svg_drawer
    RDKit::GraphMol 
    RDKit::SmilesParse 
    RDKit::Depictor
    RDKit::MolDraw2D
)
