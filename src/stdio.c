/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** stdlib
*/

#include "internal.h"
#include <stdio.h>
#include <unistd.h>

DECL_CLCC_ARGS_3(ssize_t, getline, char **, size_t *, FILE *)
DECL_CLCC_ARGS_4(int, vsnprintf, char *, size_t, const char *, va_list)
