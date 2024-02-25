/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** unistd
*/

#include <sys/socket.h>
#include "internal.h"

DECL_CLCC_ARGS_1(void *, malloc, size_t)
DECL_CLCC_ARGS_5(int, setsockopt, int, int, int, const void *, socklen_t)
