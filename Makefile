##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile NAVY
##

SRC = 	src/main.c 					\
		src/execute_command.c	\
		src/do_cd.c	\
		src/do_env.c	\
		src/do_setenv.c	\
		src/find_in_env.c	\
		src/do_unsetenv.c	\
		src/get_env.c	\
		src/find_path.c	\
		src/do_exit.c	\
		src/free_all.c	\
		src/delete_space.c	\
		src/change_pwd.c	\
		src/get_command.c	\
		src/many_command.c	\
		src/is_my_command.c	\
		src/pipe_gestions.c	\
		src/pipe_process.c	\

OBJ = $(SRC:.c=.o)

NAME = mysh

LIB_PATH = lib/my/

LIB_NAME = my

INCLUDE_PATH = includes/

INCLUDE_LIB = lib/my/include/

CFLAGS	= -Wall -Wextra -I $(INCLUDE_PATH) -I $(INCLUDE_LIB)

LFLAGS	= -L $(LIB_PATH) -l$(LIB_NAME)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)
	gcc $(OBJ) $(LFLAGS) -o $(NAME) $(CFLAGS)

clean:
	make clean -C $(LIB_PATH)
	rm -f $(OBJ) $(addsuffix ~, $(SRC))

fclean: clean
	make clean -C $(LIB_PATH)
	rm -f $(NAME)

debug: fclean
debug: CFLAGS += -g -pg
debug: LFLAGS += -pg
debug: all

re: fclean all
