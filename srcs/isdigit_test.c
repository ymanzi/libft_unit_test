#include "ft_libft_test.h"

void	isdigit_t(char s1)
{
	if (ft_isdigit(s1) == isdigit(s1))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	isdigit_test()
{
	printf("" YELLOW "~~~~~~~ ISDIGIT TEST ~~~~~~~\n" RESET "");
	isdigit_t('0');
	isdigit_t('\xfe');
	isdigit_t('A');
	isdigit_t(0);
	isdigit_t('5');
	isdigit_t('a');
	isdigit_t('\f');
	isdigit_t(' ');
	isdigit_t(12);
	printf("\n");
}