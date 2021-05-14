# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/26 14:02:22 by fdexheim          #+#    #+#              #
#    Updated: 2019/09/25 11:19:00 by fdexheim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

INCLUDES_PATH = ./inc/

SRC_PATH = ./src/
SRC_NAME =	argv.c argv2.c ft_atoi.c ft_bzero.c \
			ft_check_nb_args_required.c ft_free_string_tab.c \
			ft_get_full_input.c \
			ft_get_string_table_size.c \
			ft_directory_exists.c ft_dump_brute.c ft_dump_string_array.c \
			ft_file_exists.c \
			ft_file_or_directory_exists.c \
			ft_is_flag.c ft_is_quote.c ft_isdigit.c ft_itoa_uint64.c \
			ft_lowercase.c \
			ft_put_size_t.c ft_put_size_t_hex.c ft_put_unsigned_char_hex.c \
			ft_putchar.c ft_putnbr_bits.c ft_putstr.c ft_putstr_endl.c \
			ft_reverse_endianess32.c \
			ft_reverse_endianess64.c \
			ft_sort_string_table.c ft_strcmp.c ft_strdup.c ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c ft_testbit.c ft_tokenizer.c \
			ft_truncated_filename.c \
			ft_valid_quote.c \

OBJ_PATH = ./obj/
OBJ_NAME =	$(SRC_NAME:.c=.o)

CC =	gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all:		$(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "\033[1;32;m[$@]\033[0m : " | tr -d '\n'
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CC_FLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32;m[Compilation Successful]\033[0m"
	@echo "\033[1;36;m$(NAME)\033[1;32;m ready to go !\033[0m"

clean:
	@echo "\033[0;33;m[Clean]\033[0m              : " | tr -d '\n'
	rm -f $(OBJ)

fclean:		clean
	@echo "\033[0;31;m[Deleting $(NAME)]\033[0m : " | tr -d '\n'
	rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re:			fclean all

.PHONY:		all clean fclean re
