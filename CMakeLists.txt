cmake_minimum_required(VERSION 3.13)
project(flightSimulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(flightSimulator
        Command.cpp
        Command.h
        OpenServerCommand.cpp
        OpenServerCommand.h
        main.cpp VarCommand.cpp VarCommand.h DataReaderServer.cpp DataReaderServer.h var.cpp var.h Expression.cpp Expression.h BinaryExpression.cpp BinaryExpression.h Number.cpp Number.h Plus.cpp Plus.h Minus.cpp Minus.h Multiply.cpp Multiply.h Divide.cpp Divide.h ShuntingYard.cpp ShuntingYard.h)
