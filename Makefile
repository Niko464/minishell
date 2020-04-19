##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## This is my makefile
##


RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
WHITE=\033[1;37m
NC=\033[0m

SRC_DIR	=		src

MAIN 	=		$(SRC_DIR)/main.c

SRC		=		$(SRC_DIR)/project.c											\
				$(SRC_DIR)/init.c												\
				$(SRC_DIR)/input.c												\
				$(SRC_DIR)/shell_manager.c										\
				$(SRC_DIR)/cd/cd.c												\
				$(SRC_DIR)/env/env.c											\
				$(SRC_DIR)/env/setenv_two.c										\
				$(SRC_DIR)/env/setenv.c											\
				$(SRC_DIR)/env/unsetenv.c										\
				$(SRC_DIR)/exit/exit.c											\
				$(SRC_DIR)/other_commands/other_commands.c						\
				$(SRC_DIR)/paths.c												\
				$(SRC_DIR)/multiple_command_handling/handle_list_of_commands.c	\
				$(SRC_DIR)/expression_handling/expression_handling.c			\
				$(SRC_DIR)/expression_handling/has_expression.c					\
				$(SRC_DIR)/expression_handling/errors/error_redirect_output.c	\
				$(SRC_DIR)/utils.c

DIR_INCLUDE =	include
NAME_LIB =		libmy.a



CFLAGS		=	-Iinclude -Wall -Wextra -pedantic -Wpedantic
LFLAGS		=	-L. -lmy
DIR_LIB =		lib/my
NAME	=		mysh
NAME_TESTS	=	unit_tests

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)
OBJ_NO_MAIN =	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):		make_lib compil

make_lib:
	@cd $(DIR_LIB) && make

compil:		$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)


test:	$(OBJ_NO_MAIN)
	@./tester.sh | grep KO

debug:
	@gcc -g3 -o $(NAME) $(SRC) $(MAIN) $(CFLAGS) $(LFLAGS)

clean:
	@echo -e "${GREEN}[CLEAN] ${WHITE}Removing ${BLUE}${OBJ_LIBRARY}${WHITE}...${NC}"
	@rm -f $(OBJ_LIBRARY)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo -e "${GREEN}[CLEAN] ${WHITE}Removing ${BLUE}${NAME_LIB}${WHITE}...${NC}"
	@rm -f $(NAME_LIB)
	@cd $(DIR_LIB) && make fclean

re: fclean all
