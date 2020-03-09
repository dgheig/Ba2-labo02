cmake_minimum_required(VERSION 3.15)
project(Ba2-labo02)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++11")

add_executable(Ba2-labo02 labo_02_carvalho_bruno_gallay_david.cpp src/date.cpp src/date.h)

add_executable(testDiffDate tests/diff_date.cpp src/date.cpp src/date.h)
add_executable(testSetters tests/setters.cpp src/date.cpp src/date.h)
