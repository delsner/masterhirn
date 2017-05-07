cmake_minimum_required(VERSION 3.6)
project(masterhirn)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES run.cpp game.cpp game.h player.cpp player.h color.cpp color.h)
add_executable(masterhirn ${SOURCE_FILES})