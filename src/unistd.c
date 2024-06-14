/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** unistd
*/

#include "internal.h"

DECL_CLCC_ARGS_1(int, isatty, int)
DECL_CLCC_ARGS_0(pid_t, fork)
DECL_CLCC_ARGS_1(int, close, int)
DECL_CLCC_ARGS_3(ssize_t, write, int, const void *, size_t)
DECL_CLCC_ARGS_3(ssize_t, read, int, void *, size_t)
