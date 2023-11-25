cmake_minimum_required(VERSION 3.0.0)
project(connector VERSION 0.1.0 LANGUAGES C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/mongoose)

add_library(connector STATIC 
    src/send_data_nu.c 
    
    src/manage_conn.c
    src/mongoose/mongoose.c
)

