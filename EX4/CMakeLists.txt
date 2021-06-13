cmake_minimum_required(VERSION 3.19)
project(Ex3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ex3
        BoardGame.cpp
        BoardGame.h
        Game.h
        GameController.cpp
        GameController.h
        GameState.h
        main.cpp
        Move.h
        TicTacToe.cpp
        TicTacToe.h
        View.cpp
        View.h)
