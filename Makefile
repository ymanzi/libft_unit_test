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

CC = gcc
NAME = philo.a
LIBFT = ../../libft
CFLAGS = #-Wall -Wextra -Werror 
SRCS = main.c memcpy_test.c bzero_test.c memset_test.c memccpy_test.c \
		memmove_test.c memchr_test.c memcmp_test.c strlen_test.c strlcpy_test.c \
		strlcat_test.c strchr_test.c strrchr_test.c strnstr_test.c \
		strncmp_test.c atoi_test.c isalpha_test.c isdigit_test.c isalnum_test.c \
		isascii_test.c isprint_test.c toupper_test.c tolower_test.c \
		substr_test.c strjoin_test.c strtrim_test.c split_test.c 
OBJ = $(SRCS:.c=.o)
EXEC = part1

all:
	cp $(LIBFT)/libft.a $(LIBFT)/libft.h . 
	gcc $(CFLAGS) $(SRCS) ../libft/libft.a -o $(EXEC)

clean:
		rm -f $(EXEC) libft.a libft.h
fclean: clean
re: fclean all
