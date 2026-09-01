cmake_minimum_required(VERSION 3.10)
project(F1TeamSelector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(f1_team_selector src/main.cpp)

# Set output directory
set_target_properties(f1_team_selector PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
