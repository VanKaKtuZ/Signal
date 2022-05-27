cmake_minimum_required(VERSION 2.8)

project(Signal)

include_directories(src)

set(SOURCE main.cpp
src/TSignal.cpp
src/TGenerator.cpp
src/FileWriter.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})