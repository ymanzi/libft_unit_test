#include "ft_libft_test.h"

void	itoa_t(int nbr, char *s1)
{
	if (!strcmp(ft_itoa(nbr),s1))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	itoa_test()
{
	printf("" YELLOW "~~~~~~~ itoa TEST ~~~~~~~\n" RESET "");
	itoa_t(0, "0");
	itoa_t(-5, "-5");
	itoa_t(565, "565");
	itoa_t(6540000, "6540000");
	itoa_t(-65656594, "-65656594");
	itoa_t(-2147483648, "-2147483648");
	itoa_t(2147483647, "2147483647");
	itoa_t(3333333, "3333333");
	itoa_t(-3333333, "-3333333");
	printf("\n");
}