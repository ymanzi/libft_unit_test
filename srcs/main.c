#include "ft_libft_test.h"

void handler(int num)
{
	exit(0);
}

int main(void)
{
	printf("" CYN "-------------- PART1 ------------\n" RESET "");
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
	strdup_test();
	printf("" CYN "----------------- PART2 ------------\n" RESET "");
	substr_test();
	strjoin_test();
	strtrim_test();
	split_test();
	itoa_test();
	strmapi_test();

	return (0);
}