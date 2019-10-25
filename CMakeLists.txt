cmake_minimum_required(VERSION 3.14.5)
project(PokeBowlSim)

set(CMAKE_CXX_STANDARD 11)

add_executable(PokeBowlSim PokeBowlSim.cpp PokeBowl.cpp PokeBowl.h Pokemon.cpp Pokemon.h)