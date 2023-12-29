cmake_minimum_required(VERSION 3.10)

project(TestConnector)

add_executable(client client.c)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/connector connector)
target_link_libraries(client PRIVATE connector)
