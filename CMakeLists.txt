# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(ServerApp C)

# Specify the directories where CMake should search for include files
include_directories(include)

# Define a variable to hold the source files
file(GLOB SERVER_SOURCES "server/*.c")

# Add the executable target
add_executable(server ${SERVER_SOURCES})

# Specify the directory containing the library and link to it
target_link_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(server PRIVATE errnum)
