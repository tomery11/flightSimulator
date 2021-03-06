cmake_minimum_required(VERSION 3.13)
project(flightSimulator)

set(CMAKE_CXX_STANDARD 14)


set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(.)

add_executable(flightSimulator
        Command.h
        OpenServerCommand.cpp
        OpenServerCommand.h
        main.cpp VarCommand.cpp VarCommand.h DataReaderServer.cpp DataReaderServer.h Expression.cpp Expression.h
        BinaryExpression.cpp BinaryExpression.h Number.cpp Number.h Plus.cpp Plus.h Minus.cpp
        Minus.h Multiply.cpp Multiply.h Divide.cpp Divide.h ShuntingYard.cpp ShuntingYard.h
        SymbolsTable.cpp SymbolsTable.h DataSetClient.cpp DataSetClient.h ConnectCommand.cpp
        ConnectCommand.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h ConditionParser.h ConditionParser.cpp
        LoopCondition.cpp LoopCondition.h IfCondition.h IfCondition.cpp CommandExpression.h CommandExpression.cpp EntercCommand.cpp
        EntercCommand.h ParseUtils.cpp ParseUtils.h Command.cpp)