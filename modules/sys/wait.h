/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** wait
*/

#pragma once

#include <signal.h>
#include "../../includes/clcc.h"

__CLCC_BEGIN_DECLS

PUBLIC_PROTO_CLCC(pid_t, wait)
PUBLIC_PROTO_CLCC(pid_t, waitpid)

__CLCC_END_DECLS
