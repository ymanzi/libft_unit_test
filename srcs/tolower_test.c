#include "ft_libft_test.h"

void	tolower_t(char s1)
{
	if (ft_tolower(s1) == tolower(s1))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	tolower_test()
{
	char	*str;

	printf("" YELLOW "~~~~~~~ TOLOWER TEST ~~~~~~~\n" RESET "");
	tolower_t('0');
	tolower_t('\xfe');
	tolower_t('A');
	tolower_t(0);
	tolower_t('5');
	tolower_t('a');
	tolower_t('\f');
	tolower_t(EOF);
	tolower_t(12);
	printf("\n");
}