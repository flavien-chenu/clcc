/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** signal
*/

#pragma once

#include "../includes/clcc.h"

typedef void (*sighandler_t)(int);

PUBLIC_PROTO_CLCC(sighandler_t, signal);
