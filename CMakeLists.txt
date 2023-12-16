cmake_minimum_required(VERSION 3.26)
project(MyGames)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MyGames
        BoardGame_Classes.hpp
        GameManager.cpp
        Player.cpp
        RandomPlayer.cpp
        X_O_App.cpp
        X_O_Board.cpp
        Game1.cpp
        Game2.cpp
        Game3.cpp)
