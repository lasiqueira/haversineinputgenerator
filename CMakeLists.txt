cmake_minimum_required(VERSION 3.10)

# Set the project name
project(HaversineInputGenerator)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(HaversineInputGenerator src/main.cpp)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Platform-specific settings
if (WIN32)
    # Windows-specific settings
    message(STATUS "Configuring for Windows")
elseif (APPLE)
    # MacOS-specific settings
    message(STATUS "Configuring for MacOS")
elseif (UNIX)
    # Linux-specific settings
    message(STATUS "Configuring for Linux")
endif()

# Set build types
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")