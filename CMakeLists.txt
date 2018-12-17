cmake_minimum_required(VERSION 3.13)
project(flightSimulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(flightSimulator
        Command.h
        OpenServerCommand.cpp
        OpenServerCommand.h
        main.cpp VarCommand.cpp VarCommand.h DataReaderServer.cpp DataReaderServer.h var.cpp var.h SymbolsTable.cpp SymbolsTable.h ConnectCommand.cpp ConnectCommand.h)
