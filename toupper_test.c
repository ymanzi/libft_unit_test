#include "ft_libft_test.h"

void	toupper_t(char s1)
{
	if (ft_toupper(s1) == toupper(s1))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	toupper_test()
{
	char	*str;

	str = "toupper: ";
	write(1, str, strlen(str));
	toupper_t('0');
	toupper_t('\xfe');
	toupper_t('A');
	toupper_t(0);
	toupper_t('5');
	toupper_t('a');
	toupper_t('\f');
	toupper_t(EOF);
	toupper_t(12);
	printf("\n");
}