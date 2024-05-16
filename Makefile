##
## EPITECH PROJECT, 2024
## libc-calls-tester
## File description:
## Makefile
##

CFLAGS 			+=	-Wall -Wextra -Werror -Wno-unused-result
CMAKE_C_FLAGS 	=	-DCMAKE_C_FLAGS="$(CFLAGS)"

## Binaries names
NAME			= libclcc.a
TESTS_NAME 	    = libclcc_tests

BUILD_PATH 	= build

ifdef DEBUG
	CMAKE_FLAGS = -DCMAKE_BUILD_TYPE=Debug
else
	CMAKE_FLAGS = -DCMAKE_BUILD_TYPE=Release
endif

all:		$(NAME)

$(NAME):
			@cmake -S . -B $(BUILD_PATH) $(CMAKE_FLAGS) $(CMAKE_C_FLAGS)
			@cmake --build $(BUILD_PATH)

clean:
			@rm -rf $(BUILD_PATH)

fclean:		clean
			@rm -f $(NAME)
			@rm -rf $(LIB_PATH)
			@rm -f $(TESTS_NAME)

re:
			@$(MAKE) fclean
			@$(MAKE) all

.PHONY: all clean fclean re
DEFAULT_GOAL := all
