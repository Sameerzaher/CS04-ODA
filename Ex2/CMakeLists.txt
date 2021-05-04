cmake_minimum_required(VERSION 3.17)
project(Ex2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ex2
        BinaryExpression.h
        Div.h
        Expression.h
        main.cpp
        Minus.h
        Mul.h
        Number.h
        Plus.h)
