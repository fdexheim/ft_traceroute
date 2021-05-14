# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/26 14:02:22 by fdexheim          #+#    #+#              #
#    Updated: 2019/09/25 11:23:35 by fdexheim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_traceroute

INCLUDES_PATH = ./inc/
INCLUDE_LIBFT_PATH = ./libft/inc/

NAME_LIBFT = libft.a
PATH_LIBFT = ./libft/
FULL_LIBFT_PATH = $(addprefix $(PATH_LIBFT), $(NAME_LIBFT))

SRC_PATH = ./src/
SRC_NAME = 	check_response.c \
			checksum.c \
			dump/dump.c \
			dump/dump_icmp.c \
			dump/dump_ip.c \
			dump/dump_msghdr.c \
			init_icmp_header.c \
			init_ip_header.c \
			io.c \
			main.c \
			parse_traceroute.c \
			run.c \
			setup_socket.c \

OBJ_PATH = ./obj/
OBJ_NAME =	$(SRC_NAME:.c=.o)

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: libft $(NAME)

libft:
	@make -C $(PATH_LIBFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "\033[1;32;m[$@]\033[0m : " | tr -d '\n'
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@mkdir $(OBJ_PATH)/dump 2> /dev/null || echo "" > /dev/null
	$(CC) $(CC_FLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

$(NAME):	$(OBJ)
	$(CC) $(CC_FLAGS) -o $@ $(OBJ) $(FULL_LIBFT_PATH)
	@echo "\033[1;32;m[Compilation Successful]\033[0m"
	@echo "\033[1;36;m$(NAME)\033[1;32;m ready to go !\033[0m"

clean:
	@make clean -C $(PATH_LIBFT)
	@echo "\033[0;33;m[Clean]\033[0m              : " | tr -d '\n'
	rm -f $(OBJ)

fclean:		clean
	@make fclean -C $(PATH_LIBFT)
	@echo "\033[0;31;m[Deleting $(NAME)]\033[0m : " | tr -d '\n'
	rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re:			fclean all

.PHONY:		all clean fclean re libft
