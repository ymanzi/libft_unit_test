#	ifndef FT_LIBFT_TEST_H
#	define FT_LIBFT_TEST_H

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW	 "\033[33m"
# define CYN 	 "\e[1;96m"

#include "libft.h"
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

void	memset_test();
void	bzero_test();
void	memcpy_test();
void	handler(int num);
void	memccpy_test();
void	memmove_test();
void	memchr_test();
void	memcmp_test();
void	strlen_test();
void	strlcpy_test();
void	strlcat_test();
void	strchr_test();
void	strrchr_test();
void	strnstr_test();
void	strncmp_test();
void	atoi_test();
void	isalpha_test();
void	isdigit_test();
void	isalnum_test();
void	isascii_test();
void	isprint_test();
void	toupper_test();
void	tolower_test();
void	strdup_test();
void	substr_test();
void	strjoin_test();
void	strtrim_test();
void	split_test();
void	itoa_test();
void	strmapi_test();

#	endif