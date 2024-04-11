# 🩺 C Library Calls Controller (CLCC)

Lib CLCC allows you to control LibC calls like `malloc`, `socket`, `write`, etc. You could now use it during unit testing of your code to mock LibC calls and control function return values. With CLCC you could test all the possible scenarios of your code and pass in all branches of it.

## Installation

```bash
mkdir libs
cd libs
git clone https://github.com/flavien-chenu/clcc.git
```

## Compilation

```bash
make -C libs/clcc
gcc -o your_program main.c -L./libs/clcc -lclcc
```

## Usage
```c
#include "libs/clcc/modules/stdlib.h"

int main() {
    // Sepecify that in 2 calls malloc function will return NULL
    clcc_return_value_after(malloc, NULL, 2);
    // Enable control of malloc function
    clcc_enable_control(malloc);

    // Call malloc function
    void *ptr1 = malloc(10); // Will works fine
    void *ptr2 = malloc(10); // Will works fine
    void *ptr3 = malloc(10); // Will return NULL

    // Disable control of malloc function to avoid that malloc continue to return NULL
    clcc_disable_control(malloc);

    free(ptr1);
    free(ptr2);
    return 0;
}
```

## Documentation


### `clcc_set_return_value`
---
This function allows you to specify the return value of a function.

> ⚠️ Simply call this function does not enable the control of the function. You need to call `clcc_enable_control` to start to mock the return values.

**Parameters**
| Name | Description |
| --- | --- |
| `function` | Function name to control (not a string) |
| `value` | Return value of the function |

```c
int main(void) {
    int i = 0;

    clcc_enable_control(atoi);
    clcc_set_return_value(atoi, -78);
    i = atoi("42"); // Will return -78
    clcc_disable_control(atoi);
}
```

### `clcc_set_control`
---
This function allows you to specify enable or disable the control of a function.

**Parameters**
| Name | Description |
| --- | --- |
| `function` | Function name to control (not a string) |
| `value` | Boolean value to enable or disable the control of the function |

```c
int main(void) {
    int i = atoi("42"); // Will return 42

    clcc_set_return_value(atoi, 0);
    i = atoi("422"); // Will return 422
    clcc_set_control(atoi, true);
    i = atoi("42"); // Will return 0
    clcc_set_control(atoi, false); // Disable function control
}
```

### `clcc_control_after`
---
This function allows you to enable the control of a function after a certain number of calls.

**Parameters**
| Name | Description |
| --- | --- |
| `function` | Function name to control (not a string) |
| `number_of_calls` | Number of calls before the function returns the specified value |

```c
int main(void) {
    int number_of_calls = 2;

    clcc_set_return_value(atoi, 0);
    clcc_control_after(atoi, number_of_calls);
    clcc_enable_control(atoi);

    int a = atoi("12"); // Will return 12
    int b = atoi("178"); // Will return 178
    int c = atoi("19"); // Will return 0

    clcc_disable_control(atoi);
}
```

### `clcc_disable_control`
---
This function allows you to disable the control of a function and to stop to mock its return values.

**Parameters**
| Name | Description |
| --- | --- |
| `function` | Function name to control (not a string) |

```c
int main(void) {
    int i = atoi("42"); // Will return 42

    clcc_enable_control(atoi);
    clcc_set_return_value(atoi, 0);
    i = atoi("42"); // Will return 0
    clcc_disable_control(atoi);
    i = atoi("42"); // Will return 42
}
```

### `clcc_enable_control`
---
This function allows you to enable the control of a function and to start to mock its return values.

**Parameters**
| Name | Description |
| --- | --- |
| `function` | Function name to control (not a string) |

```c
int main(void) {
    int i = atoi("42"); // Will return 42

    clcc_enable_control(atoi);
    clcc_set_return_value(atoi, 0);
    i = atoi("42"); // Will return 0
    clcc_disable_control(atoi);
}
```

### `clcc_set_return_value_after`
---
This function allows you to specify the return value of a function after a certain number of calls.

**Parameters**
| Name | Description |
| --- | --- |
| `function` | Function name to control (not a string) |
| `value` | Return value of the function |
| `number_of_calls` | Number of calls before the function returns the specified value |

```c
int main(void) {
    int number_of_calls = 2;
    int value = 42;

    clcc_set_return_value_after(atoi, value, number_of_calls);
    clcc_enable_control(atoi);

    int a = atoi("12"); // Will return 12
    int b = atoi("178"); // Will return 178
    int c = atoi("19"); // Will return 42

    clcc_disable_control(atoi);
}
```

### `clcc_return_now`
---
This function allows you to return the specified value immediately. Is equivalent to `clcc_set_return_value_after` and `clcc_enable_control` with a number of calls equal to 0.

**Parameters**
| Name | Description |
| --- | --- |
| `function` | Function name to control (not a string) |
| `value` | Return value of the function |


```c
int main(void) {
    int value = 42;

    clcc_return_now(atoi, value);

    int a = atoi("12"); // Will return 42

    clcc_disable_control(atoi);
}
```

### `clcc_control_now`
---
This function allows you to enable the control of a function immediately. Is equivalent to `clcc_set_return_value_after` and `clcc_enable_control` with a number of calls equal to 0.

**Parameters**
| Name | Description |
| --- | --- |
| `function` | Function name to control (not a string) |

```c
int main(void) {
    int i = atoi("42"); // Will return 42

    clcc_set_return_value(atoi, 0);
    i = atoi("42"); // Will return 42
    clcc_control_now(atoi);
    i = atoi("421"); // Will return 0
    clcc_disable_control(atoi);
}
```

Made by [Flavien Chenu](https://github.com/flavien-chenu)
