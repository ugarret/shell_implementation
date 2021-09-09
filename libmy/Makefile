SRC = my_memset.c my_bzero.c my_memcpy.c my_memccpy.c my_memmove.c my_memchr.c\
		my_memcmp.c my_strlen.c my_strlcpy.c my_strlcat.c my_strchr.c\
		my_strrchr.c my_strnstr.c my_strncmp.c my_atoi.c my_isalpha.c\
		my_isdigit.c my_isalnum.c my_isascii.c my_isprint.c my_toupper.c\
		my_tolower.c my_calloc.c my_strdup.c my_substr.c my_strjoin.c\
		my_strtrim.c my_split.c my_itoa.c my_strmapi.c my_putchar_fd.c\
		my_putstr_fd.c my_putendl_fd.c my_putnbr_fd.c my_lstadd_back.c\
		my_lstnew.c my_lstclear.c my_strjoin_free_first_arg.c my_free_array.c\
		my_putchar.c

OBJ = $(SRC:.c=.o)

LIB = libmy.h

NAME = libmy.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@${CC} $(FLAGS) -I/$(LIB) -c $< -o $@

$(NAME): $(OBJ) 
	@ar rc $(NAME) $(OBJ) $(LIB)
	@echo "Library compiled successfully"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
