cmake_minimum_required(VERSION 3.12)
project(ValeNet)

set(CMAKE_CXX_STANDARD 14)

set(LIBRARY_OUTPUT_PATH lib)
set(EXECUTABLE_OUTPUT_PATH bin)

add_library(wilyautoptr SHARED src/lib/libwilyautoptr.cpp src/include/libwilyautoptr.h)
add_library(wilyloger SHARED src/include/libwilyloger.h src/lib/libwilyloger.cpp)
add_library(wilyconnection SHARED src/include/libwilyconnection.h src/lib/libwilyconnection.cpp)
add_library(wilydatagramsocket SHARED src/include/libwilydatagramsocket.h src/lib/libwilydatagramsocket.cpp)
add_library(wilyprocess SHARED src/include/libwilyprocess.h src/lib/libwilyprocess.cpp)
add_library(wilysocket SHARED src/include/libwilysocket.h src/lib/libwilysocket.cpp)
add_library(wilythread SHARED src/include/libwilythread.h src/lib/libwilythread.cpp)
add_library(wilypool SHARED src/include/libwilypool.h src/lib/libwilypool.cpp)

add_executable(ValeNet src/Vale.cpp src/op/op.cpp src/resource/Resource.cpp src/resource/Resource.h src/resource/ResourceInfo.cpp src/resource/ResourceInfo.h)

target_link_libraries(ValeNet
        wilyautoptr wilyloger wilyconnection wilydatagramsocket wilyprocess wilysocket wilythread wilypool)