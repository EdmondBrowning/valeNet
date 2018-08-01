cmake_minimum_required(VERSION 3.10)
project(ValeNet)

#head file path
INCLUDE_DIRECTORIES(.)
#source directory
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
#set environment variable
SET(TEST_MATH ${DIR_SRCS} VProcess.h VProcess.cpp)
#add executable file
ADD_EXECUTABLE(ValeNet ${TEST_MATH})