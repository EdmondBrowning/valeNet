cmake_minimum_required(VERSION 3.10)
project(ValeNet)

#head file path
INCLUDE_DIRECTORIES(.)
#source directory
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
#enable c++11
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set environment variable
SET(TEST_MATH ${DIR_SRCS} VProcess.h VProcess.cpp p2p/kad/VKad.cpp p2p/kad/VKad.h p2p/kad/VResource.cpp p2p/kad/VResource.h p2p/kad/VNode.cpp p2p/kad/VNode.h p2p/kad/VResourceTable.cpp p2p/kad/VResourceTable.h p2p/kad/VKBucket.cpp p2p/kad/VKBucket.h)
#add executable file
ADD_EXECUTABLE(ValeNet ${TEST_MATH})