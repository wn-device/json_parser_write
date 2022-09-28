cmake_minimum_required(VERSION 3.0.0)
project(json_parse_write VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(json_parse_write main.cc cJSON.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
