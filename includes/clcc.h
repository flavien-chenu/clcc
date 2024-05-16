/*
** EPITECH PROJECT, 2024
** libc-calls-tester
** File description:
** public
*/

#pragma once

#include <stdbool.h>

#ifdef __cplusplus
    #define __CLCC_BEGIN_DECLS extern "C" {
#else
    #define __CLCC_BEGIN_DECLS
#endif

#ifdef __cplusplus
    #define __CLCC_END_DECLS }
#else
    #define __CLCC_END_DECLS
#endif

__CLCC_BEGIN_DECLS

#define PUBLIC_PROTO_CLCC(t_return, func_name) \
    void clcc_##func_name##_control_after(int nb_calls); \
    void clcc_##func_name##_control_now(void); \
    void clcc_##func_name##_set_control(bool enabled); \
    void clcc_##func_name##_set_return_value(t_return value);

/**
 * @brief Define number of calls after which function will be controlled
 * @param func_name Function name to control
 * @param nb_calls Number of calls after which function will be controlled
 */
#define clcc_control_after(func_name, nb_calls) \
    clcc_##func_name##_control_after(nb_calls)

/**
 * @brief Enable immediate control of function
 * @param func_name Function name to control
 * @note Control of function is directly enabled and number of calls is set to 0.
 */
#define clcc_control_now(func_name) \
    clcc_##func_name##_set_control(true); \
    clcc_##func_name##_control_after(0) \

/**
 * @brief Enable immediate control of function and set return value
 * @param func_name Function name to control
 * @param value Return value that function will return
 */
#define clcc_return_now(func_name, value) \
    clcc_##func_name##_set_return_value(value); \
    clcc_control_now(func_name)

/**
 * @brief Enable or disable control of function
 * @param func_name Function name to control
 * @param enabled Enable or disable control of function
 */
#define clcc_set_control(func_name, enabled) \
    clcc_##func_name##_set_control(enabled)

/**
 * @brief Set return value that function will return when control is enabled
 * @param func_name Function name to control
 * @param value Return value that function will return when control is enabled
 */
#define clcc_set_return_value(func_name, value) \
    clcc_##func_name##_set_return_value(value)

/**
 * @brief Set value that function will return after number of calls
 * @param func_name Function name to control
 * @param value Return value that function will return after number of calls
 * @param nb_calls Number of calls after which function will return value
 */
#define clcc_return_value_after(func_name, value, nb_calls) \
    clcc_##func_name##_set_return_value(value); \
    clcc_##func_name##_control_after(nb_calls)


/**
 * @brief Enable control of function
 * @param func_name Function name to control
 */
#define clcc_enable_control(func_name) \
    clcc_##func_name##_set_control(true)

/**
 * @brief Disable control of function
 * @param func_name Function name to control
 */
#define clcc_disable_control(func_name) \
    clcc_##func_name##_set_control(false)

__CLCC_END_DECLS
