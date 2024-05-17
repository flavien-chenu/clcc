/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** msg
*/

#pragma once

#include "../../includes/clcc.h"

__CLCC_BEGIN_DECLS

PUBLIC_PROTO_CLCC(int, msgget)
PUBLIC_PROTO_CLCC(int, msgsnd)
PUBLIC_PROTO_CLCC(int, msgrcv)
PUBLIC_PROTO_CLCC(int, msgctl)

__CLCC_END_DECLS
