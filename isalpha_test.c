#include "ft_libft_test.h"

void	isalpha_t(char s1)
{
	if (ft_isalpha(s1) == isalpha(s1))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	isalpha_test()
{
	char	*str;

	str = "isalpha: ";
	write(1, str, strlen(str));
	isalpha_t('0');
	isalpha_t('\xfe');
	isalpha_t('A');
	isalpha_t(0);
	isalpha_t('5');
	isalpha_t('a');
	isalpha_t('\f');
	isalpha_t(' ');
	isalpha_t(12);
	printf("\n");
}