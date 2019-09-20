cmake_minimum_required(VERSION 3.0)
project(qserve)
find_package (Threads)
set(CMAKE_CXX_STANDARD 14)

add_executable(qserve main.cpp args.cpp serverconfig.cpp)
target_link_libraries (qserve ${CMAKE_THREAD_LIBS_INIT})
