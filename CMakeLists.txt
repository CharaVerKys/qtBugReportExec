cmake_minimum_required(VERSION 3.16)
project(BugReport)

#set(CMAKE_PREFIX_PATH "/opt/Qt64") # qt6.4
set(CMAKE_PREFIX_PATH "/opt/Qt6") #qt6.8

set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(BugReport main.cpp)

target_link_libraries(BugReport Qt6::Core Qt6::Widgets)
