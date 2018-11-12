cmake_minimum_required(VERSION 3.10)
project(ValeNet)

#head file path
INCLUDE_DIRECTORIES(.)
#source directory
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
#enable c++11
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set environment variable
SET(TEST_MATH ${DIR_SRCS} p2p/kad/VKad.cpp p2p/kad/VKad.h p2p/kad/VResource.cpp p2p/kad/VResource.h p2p/kad/VNode.cpp p2p/kad/VNode.h p2p/kad/VResourceTable.cpp p2p/kad/VResourceTable.h p2p/kad/VKBucket.cpp p2p/kad/VKBucket.h p2p/kad/VSHA1.cpp p2p/kad/VSHA1.h tools/Mac.cpp tools/Mac.h test.cpp)
#add executable file

set(LIBRARY_OUTPUT_PATH lib)
set(EXECUTABLE_OUTPUT_PATH bin)

add_library(wilyautoptr SHARED lib/libwilyautoptr.cpp include/libwilyautoptr.h)
add_library(wilyloger SHARED include/libwilyloger.h lib/libwilyloger.cpp)
add_library(wilyconnection SHARED include/libwilyconnection.h lib/libwilyconnection.cpp)
add_library(wilydatagramsocket SHARED include/libwilydatagramsocket.h lib/libwilydatagramsocket.cpp)
add_library(wilyprocess SHARED include/libwilyprocess.h lib/libwilyprocess.cpp)
add_library(wilysocket SHARED include/libwilysocket.h lib/libwilysocket.cpp)
add_library(wilythread SHARED include/libwilythread.h lib/libwilythread.cpp)

ADD_EXECUTABLE(ValeNet ${TEST_MATH})

target_link_libraries(ValeNet wilyautoptr wilyloger wilyconnection wilydatagramsocket wilyprocess wilysocket wilythread)