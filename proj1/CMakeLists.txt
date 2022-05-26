cmake_minimum_required(VERSION 3.22)
project(game)

set(CMAKE_CXX_STANDARD 17)

add_executable(game main.cpp Board.cpp Board.h Boards.cpp Boards.h Game.cpp Game.h)
