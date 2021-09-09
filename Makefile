CC =			gcc

FLAGS =			-Werror -Wextra -Wall -g

RM =			rm -rf

DIR_HEADERS =	./

LIBMY =			libmy/libmy.a

TERM =			-ltermcap

SRC =			main.c \
				commando.c \
				my_puterror.c \
				work_with_pipe.c \
				work_with_redirect.c \
				parser/parser.c \
				parser/pars_utils.c \
				parser/pars_separators.c \
				parser/pars_spec_symbol.c \
				parser/pars_redirects.c \
				parser/pars_res.c \
				term/work_with_terminal.c \
				term/signals.c \
				term/after_press_key.c \
				builtin_commands/echo.c \
				builtin_commands/cd.c \
				builtin_commands/env.c \
				builtin_commands/exit.c \
				builtin_commands/export.c \
				builtin_commands/pwd.c \
				builtin_commands/unset.c \
				builtin_commands/validation.c \
				for_env/sort_elements.c \
				for_env/add_element.c \
				for_env/new_element.c \
				for_env/get_env.c \
				for_env/delete_element.c \
				for_env/replace_value.c \
				for_env/search_element.c \
				for_env/add_value.c \
				for_env/list_with_env_to_array.c

OBJS =			$(SRC:.c=.o)

NAME =			minishell

.PHONY:			all, clean, fclean, re

all:			$(NAME)

$(NAME) :		$(OBJS)
				@make -C ./libmy
				@$(CC) $(FLAGS) -I $(DIR_HEADERS) $(LIBMY) $(TERM) $(OBJS) -o $(NAME)
				@echo "Minishell compiled successfully"

%.o: %.c
				@gcc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@make clean -C ./libmy
				@$(RM) $(LIBMY)
				@echo "Library deleted successfully"
				@$(RM) $(NAME)
				@echo "Minishell deleted successfully"

re:				fclean all