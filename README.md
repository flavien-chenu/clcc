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
    clcc_set_return_value_after(malloc, NULL, 2);
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

#
Made by [Flavien Chenu](https://github.com/flavien-chenu)
