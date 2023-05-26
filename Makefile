# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmajor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 13:54:49 by brmajor           #+#    #+#              #
#    Updated: 2023/05/26 14:34:50 by brmajor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = chunks_to_b.c errorcheck.c free.c index.c main.c makestacks.c operations.c sizecheck.c sort_in_A.c sort_small.c sort_utils.c push_swap.h \

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

RM = rm -rf

$(NAME):
	@echo Making libft...
	@make -C libft/ > /dev/null
	@echo Compiling push_swap...
	@$(CC) $(CFLAGS) $(SRC) -L libft/ -l ft -o $(NAME)

all: $(NAME)

clean:
	@echo Removing obj/ and libft...
	@make -C libft/ fclean > /dev/null

fclean: clean
	@echo Removing push_swap...
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
