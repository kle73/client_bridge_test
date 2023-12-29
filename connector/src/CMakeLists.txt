add_subdirectory(util)
add_subdirectory(mongoose)

add_library(connector connector.c)

target_include_directories(connector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(connector PUBLIC util mongoose)

