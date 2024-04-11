##
## EPITECH PROJECT, 2024
## libc-calls-tester
## File description:
## Makefile
##

SRC_SHORT		=	stdlib.c \
					signal.c \
					\
					sys/socket.c \

## Project sources
SRC_DIR 		= 	src/
SRC 			=	$(addprefix $(SRC_DIR), $(SRC_SHORT))
SRC_OBJ 		= 	$(SRC:.c=.o)
SRC_GCNO 		=	$(SRC:.c=.gcno)
SRC_GCDA 		=	$(SRC:.c=.gcda)

## Unit tests sources
TESTS_DIR 		= 	tests/unit/
TESTS 			=	$(addprefix $(TESTS_DIR), $(TESTS_SHORT))
TESTS_OBJ 		= 	$(TESTS:.c=.o)

## Compilation
INCLUDES 		= 	-I./includes/

LDFLAGS 		=
LDLIBS 			=
CFLAGS 			+=	-Wall -Wextra -Werror $(INCLUDES)

TESTS_LDFLAGS 	= $(LDFLAGS)
TESTS_LDLIBS 	= $(LDLIBS) -lcriterion
TESTS_CFLAGS 	= $(CFLAGS) --coverage

CC 				= 	gcc

## Colors and logs
S_GREEN			=	\033[0;32m
S_ORANGE		=	\033[0;33m
S_RED			=	\033[0;31m
S_BLUE			=	\033[0;34m
S_MAGENTA		=	\033[0;37m
S_GREY			=	\033[0;30m
S_BOLD			=	\033[1m
S_END			=	\033[0m
COMPILING_O_LOG = "$(S_BLUE)📑 Compiling source $(S_BOLD)%s$(S_END)\n"
BIN_BUILD_LOG	= "$(S_RED)📦 Building library $(S_BOLD)%s$(S_END)\n"
BIN_SUCCESS_LOG = "$(S_GREEN)✅ $(S_BOLD)%s$(S_END)\
$(S_GREEN)successfully built $(S_END)\n"
RUNNING_TESTS_LOG = "$(S_BLUE)🧪 Running tests from $(S_BOLD)%s$(S_END)\n"
CLEAN_PROJECT_LOG = "🧽 Project has been cleaned\n"

## Binaries names
NAME			= libclcc.a
TESTS_NAME 	    = libclcc_tests

%.o: %.c
				@printf $(COMPILING_O_LOG) $<
				@$(CC) $(CFLAGS) -c $< -o $@

%.gcno: %.c
				@printf $(COMPILING_O_LOG) $<
				@$(CC) -c $< -o $*.o $(CFLAGS) --coverage

$(NAME):		$(SRC_OBJ)
				@printf $(BIN_BUILD_LOG) $(NAME)
				@ar rc $(NAME) $(SRC_OBJ)
				@printf $(BIN_SUCCESS_LOG) $(NAME)

$(TESTS_NAME):	$(TESTS_OBJ) $(SRC_GCNO)
				@printf $(BIN_BUILD_LOG) $(TESTS_NAME)
				@$(CC) -o $(TESTS_NAME) $(SRC_OBJ) $(TESTS_OBJ) \
				$(TESTS_LDFLAGS) $(TESTS_LDLIBS) $(TESTS_CFLAGS)
				@printf $(BIN_SUCCESS_LOG) $(TESTS_NAME)

all: 			$(NAME)

clean:			clean_src
				@rm -f $(TESTS_OBJ)

clean_src:
				@rm -f $(SRC_OBJ)
				@rm -f $(SRC_GCNO)
				@rm -f $(SRC_GCDA)
				@rm -f $(MAIN_OBJ)

fclean: 		clean
				@rm -f $(NAME)
				@rm -f $(TESTS_NAME)
				@printf $(CLEAN_PROJECT_LOG)

re:
				@$(MAKE) fclean -s
				@$(MAKE) all -s

tests_criterion: $(TESTS_NAME)
				@rm -f $(SRC_GCDA)
				@printf $(RUNNING_TESTS_LOG) $(TESTS_NAME)
				@./$(TESTS_NAME) -j1

tests_run:  	tests_criterion

coverage:
				@gcovr

coverage_branch:
				@gcovr --branch

update:
				@./pull.sh .

.PHONY: all clean clean_src fclean re \
		tests_criterion tests_run \
		coverage coverage_branch update
DEFAULT_GOAL := all
