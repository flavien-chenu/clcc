/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** socket
*/

#include <sys/socket.h>
#include "internal.h"

DECL_CLCC_ARGS_3(int, socket, int, int, int)
DECL_CLCC_ARGS_5(int, setsockopt, int, int, int, const void *, socklen_t)
