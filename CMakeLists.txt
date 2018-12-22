cmake_minimum_required(VERSION 3.12)
project(1)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(1
        inc/Exception.hpp
        inc/Factory.hpp
        inc/IOperand.hpp
        inc/Operand.hpp
        src/Exception.cpp
        src/Factory.cpp
        src/main.cpp
        abstract-vm.en.pdf
        exemple.avm
        exemple2.avm
        exemple3.avm
        Makefile
        toRemember src/Lexer.cpp inc/Lexer.hpp inc/Lexer.hpp src/Parser.cpp inc/Parser.hpp src/Executor.cpp inc/Executor.hpp)
