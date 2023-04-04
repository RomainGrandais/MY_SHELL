##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## build lib
##

SRC = 	src/int/is_digit.c	\
		src/int/my_getnbr.c	\
		src/int/my_is_prime.c	\
		src/int/my_isneg.c	\
		src/int/len_int.c	\
		\
		src/maths/my_compute_power_rec.c	\
		src/maths/my_compute_square_root.c	\
		src/maths/my_find_prime_sup.c	\
		\
		src/print/my_printf.c	\
		src/print/my_put_nbr.c	\
		src/print/my_putchar.c	\
		src/print/my_putstr.c	\
		src/print/my_show_word_array.c	\
		src/print/put_for_miniprintf.c	\
		\
		src/string/make_buffer.c	\
		src/string/my_revstr.c	\
		src/string/my_str_to_word_array.c	\
		src/string/my_strcapitalize.c	\
		src/string/my_strcat.c	\
		src/string/my_strcmp.c	\
		src/string/my_strcpy.c	\
		src/string/my_strdup.c	\
		src/string/my_strlen.c	\
		src/string/my_strlowcase.c	\
		src/string/my_strncat.c	\
		src/string/my_strncmp.c	\
		src/string/my_strncpy.c	\
		src/string/my_strstr.c	\
		src/string/my_strupcase.c	\
		src/string/int_to_string.c	\
		src/string/str_to_array_space.c	\
		src/string/concat_strings.c	\
		src/string/is_letters.c	\
		src/string/my_strtok.c	\
		\
		src/tab/make_tab_with_path.c	\
		\
		src/stat/make_buffer_ws.c	\
		src/stat/size.c	\
		\


OBJ = $(SRC:.c=.o)

GCC = gcc

INCLUDE_FLAGS = \
	-I include

C_WARNING_FLAGS = -Wextra -Wall
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: libmy.a
.PHONY : all

libmy.a: $(OBJ)
	@ar rc $@ $(OBJ)
.PHONY : libmy.a

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete

re: clean all
