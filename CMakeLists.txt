cmake_minimum_required(VERSION 3.27)
project(clcc)

set(CMAKE_C_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

add_library(clcc STATIC
        includes/clcc.h
        includes/internal.h
        src/signal.c
        src/stdio.c
        src/stdlib.c
        src/string.c
        src/unistd.c
        src/sys/select.c
        src/sys/socket.c
        src/sys/msg.c
        src/sys/wait.c
        modules/signal.h
        modules/stdio.h
        modules/stdlib.h
        modules/string.h
        modules/unistd.h
        modules/sys/select.h
        modules/sys/socket.h
        modules/sys/msg.h
        modules/sys/wait.h
)

target_include_directories(clcc PUBLIC includes)
