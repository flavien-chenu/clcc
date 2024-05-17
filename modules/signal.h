/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** signal
*/

#pragma once

#include "../includes/clcc.h"

__CLCC_BEGIN_DECLS

typedef void (*sighandler_t)(int);

PUBLIC_PROTO_CLCC(sighandler_t, signal)

__CLCC_END_DECLS
