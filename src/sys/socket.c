/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** socket
*/

#include "internal.h"
#include <sys/socket.h>

DECL_CLCC_ARGS_3(int, socket, int, int, int)
DECL_CLCC_ARGS_5(int, setsockopt, int, int, int, const void *, socklen_t)
DECL_CLCC_ARGS_3(int, bind, int, const struct sockaddr *, socklen_t)
DECL_CLCC_ARGS_2(int, listen, int, int)
DECL_CLCC_ARGS_3(int, accept, int, struct sockaddr *, socklen_t *)
DECL_CLCC_ARGS_3(int, connect, int, const struct sockaddr *, socklen_t)
