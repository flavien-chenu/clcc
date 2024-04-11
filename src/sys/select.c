/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** select
*/

#include "internal.h"
#include <sys/select.h>

DECL_CLCC_ARGS_5(int, select, int, fd_set *, fd_set *, fd_set *, struct timeval *)
