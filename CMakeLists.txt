cmake_minimum_required(VERSION 3.10.2)
project(stopwatch)

# Set basic options
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)
 
include_directories(include)
 
file(GLOB SOURCES "src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME} pthread)

# Setup Catch2
file(GLOB TEST_SOURCES "tests/*.cpp")
add_subdirectory(vendor/catch)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vendor/catch/contrib")
add_executable("${PROJECT_NAME}_test" ${TEST_SOURCES})
target_link_libraries("${PROJECT_NAME}_test" Catch2::Catch2)
target_link_libraries("${PROJECT_NAME}_test" ${PROJECT_NAME})

include(CTest)
include(Catch)

catch_discover_tests("${PROJECT_NAME}_test")
