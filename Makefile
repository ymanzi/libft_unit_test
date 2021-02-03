# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 14:05:13 by ymanzi            #+#    #+#              #
#    Updated: 2020/11/22 13:49:15 by ymanzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = ../libft
CFLAGS = #-Wall -Wextra -Werror 
SRCS = ./srcs/*.c
BONUS = ./bonus/*.c
EXEC = libft_test
EXEC_BONUS = bonus_test
CC = gcc

$(EXEC): all

all:
	(cd $(LIBFT_PATH) && $(MAKE))
	cp $(LIBFT_PATH)/libft.h srcs
	cp $(LIBFT_PATH)/libft.a .  
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_PATH)/libft.a -o $(EXEC)

run: all
	./$(EXEC)

bonus: all
	(cd $(LIBFT_PATH) && $(MAKE) bonus)
	$(CC) $(CFLAGS) $(BONUS) $(LIBFT_PATH)/libft.a -o $(EXEC_BONUS)
	./$(EXEC_BONUS)

clean:
	rm -f $(EXEC) $(EXEC_BONUS) libft.a libft.h 
fclean: clean
re: fclean all
