cmake_minimum_required(VERSION 3.26)
project(Algorithms___Data_Structure C)

set(CMAKE_C_STANDARD 11)

add_executable(Algorithms___Data_Structure main.c
        LinkedList/LinkedList.c
        LinkedList/LinkedList.h
        Utils.h
        ReturnCode.c)
