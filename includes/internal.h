/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** symbol
*/

#pragma once

#ifndef RTLD_NEXT
    #define RTLD_NEXT	((void *) -1l)
#endif

#include <dlfcn.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

// Enable C++ compilers to link these functions correctly
#ifdef __cplusplus
extern "C" {
#endif

#define CLCC_DATA_CTX_NAME(func_name) clcc_##func_name##_data_ctx
#define CLCC_DATA_CTX_TYPE(func_name) clcc_##func_name##_data_ctx_t
#define CLCC_DATA_CTX_STRUCT(func_name) s_clcc_##func_name##_data_ctx

#define CLCC_LOG_ERR(msg) write(2, "[CLCC] Error: " msg "\n", sizeof("[CLCC] Error: " msg "\n") - 1)
#define CLCC_LOG_INFO(msg) write(1, "[CLCC] Info: " msg "\n", sizeof("[CLCC] Info: " msg "\n") - 1)

#define DECL_CLCC_DATA_CTX_STRUCT(func_name, t_return) \
    typedef struct CLCC_DATA_CTX_STRUCT(func_name) { \
        bool        control; \
        int         counter; \
        t_return    return_value; \
    } CLCC_DATA_CTX_TYPE(func_name)

#define DECL_CLCC_DATA_CTX(func_name) \
    static CLCC_DATA_CTX_TYPE(func_name) CLCC_DATA_CTX_NAME(func_name) = { \
        .control = false, \
        .counter = 0 \
    }

#define DECL_CLCC_CONTROL_AFTER(func_name) \
    void clcc_##func_name##_control_after(int nb_calls) { \
        CLCC_DATA_CTX_NAME(func_name).counter = nb_calls; \
    }

#define DECL_CLCC_CONTROL_MANAGER(func_name) \
    void clcc_##func_name##_set_control(bool enabled) { \
        CLCC_DATA_CTX_NAME(func_name).control = enabled; \
    }

#define DECL_CLCC_RETURN_MANAGER(t_return, func_name) \
    void clcc_##func_name##_set_return_value(t_return value) { \
        CLCC_DATA_CTX_NAME(func_name).return_value = value; \
    }

#define DECL_CLCC_COMMONS(t_return, func_name) \
    DECL_CLCC_DATA_CTX_STRUCT(func_name, t_return); \
    DECL_CLCC_DATA_CTX(func_name); \
    DECL_CLCC_CONTROL_AFTER(func_name) \
    DECL_CLCC_CONTROL_MANAGER(func_name) \
    DECL_CLCC_RETURN_MANAGER(t_return, func_name)

#define PREVENT_NOT_FOUND_REAL_SYMBOL(func_name) \
    if (!real_func) { \
        CLCC_LOG_ERR("Real symbol not found:" #func_name); \
        exit(1); \
    }

#define DECL_CLCC_ARGS_0(t_return, func_name) \
    DECL_CLCC_COMMONS(t_return, func_name); \
    t_return func_name() { \
        if (!CLCC_DATA_CTX_NAME(func_name).control || CLCC_DATA_CTX_NAME(func_name).counter > 0) { \
            t_return (*real_func)() = dlsym(RTLD_NEXT, #func_name); \
            PREVENT_NOT_FOUND_REAL_SYMBOL(func_name); \
            CLCC_DATA_CTX_NAME(func_name).counter -= 1; \
            return real_func(); \
        } \
        return CLCC_DATA_CTX_NAME(func_name).return_value; \
    }

#define DECL_CLCC_ARGS_1(t_return, func_name, t_arg1) \
    DECL_CLCC_COMMONS(t_return, func_name); \
    t_return func_name(t_arg1 arg1) { \
        if (!CLCC_DATA_CTX_NAME(func_name).control || CLCC_DATA_CTX_NAME(func_name).counter > 0) { \
            t_return (*real_func)(t_arg1) = dlsym(RTLD_NEXT, #func_name); \
            PREVENT_NOT_FOUND_REAL_SYMBOL(func_name); \
            CLCC_DATA_CTX_NAME(func_name).counter -= 1; \
            return real_func(arg1); \
        } \
        return CLCC_DATA_CTX_NAME(func_name).return_value; \
    }

#define DECL_CLCC_ARGS_2(t_return, func_name, t_arg1, t_arg2) \
    DECL_CLCC_COMMONS(t_return, func_name); \
    t_return func_name(t_arg1 arg1, t_arg2 arg2) { \
        if (!CLCC_DATA_CTX_NAME(func_name).control || CLCC_DATA_CTX_NAME(func_name).counter > 0) { \
            t_return (*real_func)(t_arg1, t_arg2) = dlsym(RTLD_NEXT, #func_name); \
            PREVENT_NOT_FOUND_REAL_SYMBOL(func_name); \
            CLCC_DATA_CTX_NAME(func_name).counter -= 1; \
            return real_func(arg1, arg2); \
        } \
        return CLCC_DATA_CTX_NAME(func_name).return_value; \
    }

#define DECL_CLCC_ARGS_3(t_return, func_name, t_arg1, t_arg2, t_arg3) \
    DECL_CLCC_COMMONS(t_return, func_name); \
    t_return func_name(t_arg1 arg1, t_arg2 arg2, t_arg3 arg3) { \
        if (!CLCC_DATA_CTX_NAME(func_name).control || CLCC_DATA_CTX_NAME(func_name).counter > 0) { \
            t_return (*real_func)(t_arg1, t_arg2, t_arg3) = dlsym(RTLD_NEXT, #func_name); \
            PREVENT_NOT_FOUND_REAL_SYMBOL(func_name); \
            CLCC_DATA_CTX_NAME(func_name).counter -= 1; \
            return real_func(arg1, arg2, arg3); \
        } \
        return CLCC_DATA_CTX_NAME(func_name).return_value; \
    }

#define DECL_CLCC_ARGS_4(t_return, func_name, t_arg1, t_arg2, t_arg3, t_arg4) \
    DECL_CLCC_COMMONS(t_return, func_name); \
    t_return func_name(t_arg1 arg1, t_arg2 arg2, t_arg3 arg3, t_arg4 arg4) { \
        if (!CLCC_DATA_CTX_NAME(func_name).control || CLCC_DATA_CTX_NAME(func_name).counter > 0) { \
            t_return (*real_func)(t_arg1, t_arg2, t_arg3, t_arg4) = dlsym(RTLD_NEXT, #func_name); \
            PREVENT_NOT_FOUND_REAL_SYMBOL(func_name); \
            CLCC_DATA_CTX_NAME(func_name).counter -= 1; \
            return real_func(arg1, arg2, arg3, arg4); \
        } \
        return CLCC_DATA_CTX_NAME(func_name).return_value; \
    }

#define DECL_CLCC_ARGS_5(t_return, func_name, t_arg1, t_arg2, t_arg3, t_arg4, t_arg5) \
    DECL_CLCC_COMMONS(t_return, func_name); \
    t_return func_name(t_arg1 arg1, t_arg2 arg2, t_arg3 arg3, t_arg4 arg4, t_arg5 arg5) { \
        if (!CLCC_DATA_CTX_NAME(func_name).control || CLCC_DATA_CTX_NAME(func_name).counter > 0) { \
            t_return (*real_func)(t_arg1, t_arg2, t_arg3, t_arg4, t_arg5) = dlsym(RTLD_NEXT, #func_name); \
            PREVENT_NOT_FOUND_REAL_SYMBOL(func_name); \
            CLCC_DATA_CTX_NAME(func_name).counter -= 1; \
            return real_func(arg1, arg2, arg3, arg4, arg5); \
        } \
        return CLCC_DATA_CTX_NAME(func_name).return_value; \
    }

#define DECL_CLCC_ARGS_6(t_return, func_name, t_arg1, t_arg2, t_arg3, t_arg4, t_arg5, t_arg6) \
    DECL_CLCC_COMMONS(t_return, func_name); \
    t_return func_name(t_arg1 arg1, t_arg2 arg2, t_arg3 arg3, t_arg4 arg4, t_arg5 arg5, t_arg6 arg6) { \
        if (!CLCC_DATA_CTX_NAME(func_name).control || CLCC_DATA_CTX_NAME(func_name).counter > 0) { \
            t_return (*real_func)(t_arg1, t_arg2, t_arg3, t_arg4, t_arg5, t_arg6) = dlsym(RTLD_NEXT, #func_name); \
            PREVENT_NOT_FOUND_REAL_SYMBOL(func_name); \
            CLCC_DATA_CTX_NAME(func_name).counter -= 1; \
            return real_func(arg1, arg2, arg3, arg4, arg5, arg6); \
        } \
        return CLCC_DATA_CTX_NAME(func_name).return_value; \
    }

#ifdef __cplusplus
}
#endif
