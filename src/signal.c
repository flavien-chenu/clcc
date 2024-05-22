/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** signal
*/

#include "internal.h"

typedef void (*sighandler_t)(int);

DECL_CLCC_ARGS_2(sighandler_t, signal, int, sighandler_t)
DECL_CLCC_ARGS_2(int, kill, pid_t, int)
