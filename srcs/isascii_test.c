#include "ft_libft_test.h"

void	isascii_t(int s1)
{
	if (ft_isascii(s1) == isascii(s1))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	isascii_test()
{
	printf("" YELLOW "~~~~~~~ ISASCII TEST ~~~~~~~\n" RESET "");
	isascii_t('0');
	isascii_t('\xfe');
	isascii_t('A');
	isascii_t(0);
	isascii_t('a');
	isascii_t('\f');
	isascii_t(12);
	printf("\n");
}