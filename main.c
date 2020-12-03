#include "ft_libft_test.h"

void handler(int num)
{
	exit(0);
}

int main(void)
{
	printf("-----------------PART1--------------------\n");
	memset_test();
	bzero_test();
	memcpy_test();
	memccpy_test();
	memmove_test();
	memchr_test();
	memcmp_test();
	strlen_test();
	strlcpy_test();
	strlcat_test();
	strchr_test();
	strrchr_test();
	strnstr_test();
	strncmp_test();
	atoi_test();
	isalpha_test();
	isdigit_test();
	isalnum_test();
	isascii_test();
	isprint_test();
	toupper_test();
	tolower_test();
	printf("-----------------PART2--------------------\n");
	substr_test();
	strjoin_test();
	strtrim_test();
	split_test();

	return (0);
}