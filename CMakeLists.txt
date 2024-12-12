cmake_minimum_required(VERSION 3.10)
project(pr5_svd)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(pr5_svd
    src/main.c 
    src/users.c 
    src/processes.c 
    src/log.c 
    src/errors.c 
    src/help.c 
    src/utils.c)

target_include_directories(pr5_svd PUBLIC include)