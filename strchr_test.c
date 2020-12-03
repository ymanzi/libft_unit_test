#include "ft_libft_test.h"

void segv_test_strchr()
{
	signal(SIGSEGV, handler);
	ft_strchr(0, 12);
	exit(1);
}

void strchr_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strchr();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	strchr_t(char *str, char c)
{
	if (ft_strchr(str, c) == strchr(str, c))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	strchr_test()
{
	char	*tab[11];
	char	c[5];

	write(1, "strchr:  ", 9);
	strchr_segv_test();
	tab[0] = "lol";
	tab[1] = " ";
	tab[2] = "bon";
	tab[3] = "asdklfjasdfj////asdf'''asdf3##";
	tab[4] = "the\0hidden";
	tab[5] = "Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.";
	tab[6] = "\xfe\xff";
	tab[7] = "\x02\x01";
	tab[8] = "\x01\x02";
	tab[9] = "\xff\xff";
	tab[10] = "\xff\xfe";

	c[0] = '\0';
	c[1] = '\xfe';
	c[2] = '\x02';
	c[3] = 'r';
	c[4] = '\n';

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 5; j++)
			strchr_t(tab[i], c[j]);
	}
	printf("\n");
}