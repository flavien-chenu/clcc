/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** select
*/

#include "internal.h"

DECL_CLCC_ARGS_2(int, msgget, key_t, int)
DECL_CLCC_ARGS_4(int, msgsnd, int, const void *, size_t, int)
DECL_CLCC_ARGS_5(ssize_t, msgrcv, int, void *, size_t, long, int)
DECL_CLCC_ARGS_2(int, msgctl, int, int)
