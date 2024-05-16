cmake_minimum_required(VERSION 3.27)
project(clcc)

set(CMAKE_C_STANDARD 17)

add_library(clcc STATIC
        src/signal.c
        src/stdio.c
        src/stdlib.c
        src/unistd.c
        src/sys/select.c
        src/sys/socket.c
        src/sys/msg.c
)

target_include_directories(clcc PUBLIC includes)
