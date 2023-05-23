# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmajor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 13:54:49 by brmajor           #+#    #+#              #
#    Updated: 2023/05/22 18:34:36 by brmajor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(shell find . -name "*.c" -not -path "./push_swap_visualizer/*")

OBJ_DIR = obj/

OBJ_FILES = $(SRC:%.c=$(OBJ_DIR)%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

RM = rm -rf

MKDIR = mkdir -p $(@D)

$(OBJ_DIR)%.o: %.c 
	       $(MKDIR) 
	       $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES) 
	 $(MKDIR) 
	 $(CC) -g -o $(NAME) $(OBJ_FILES) 
	 chmod +x $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
