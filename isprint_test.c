#include "ft_libft_test.h"

void	isprint_t(char s1)
{
	if (ft_isprint(s1) == isprint(s1))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	isprint_test()
{
	char	*str;

	str = "isprint: ";
	write(1, str, strlen(str));
	isprint_t('0');
	isprint_t('\xfe');
	isprint_t('A');
	isprint_t(0);
	isprint_t(31);
	isprint_t('a');
	isprint_t('\f');
	isprint_t(127);
	isprint_t(12);
	printf("\n");
}