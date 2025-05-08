cmake_minimum_required(VERSION 3.10)
project(MiniSparkCPP)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC_FILES "src/*.cpp")

add_executable(MiniSparkCPP ${SRC_FILES})

# <<< Add this so headers in src/ can be found
target_include_directories(MiniSparkCPP
  PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)
