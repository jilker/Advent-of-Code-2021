cmake_minimum_required(VERSION 3.0.0)
project(day_9 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(day_9 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
