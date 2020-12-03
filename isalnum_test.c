#include "ft_libft_test.h"

void	isalnum_t(char s1)
{
	if (ft_isalnum(s1) == isalnum(s1))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	isalnum_test()
{
	char	*str;

	str = "isalnum: ";
	write(1, str, strlen(str));
	isalnum_t('0');
	isalnum_t('\xfe');
	isalnum_t('A');
	isalnum_t(0);
	isalnum_t('5');
	isalnum_t('a');
	isalnum_t('\f');
	isalnum_t(' ');
	isalnum_t(12);
	printf("\n");
}