#include "ft_libft_test.h"

void segv_test_strnstr1()
{
	signal(SIGSEGV, handler);
	ft_strnstr(0, "abcdef", 4);
	exit(1);
}

void segv_test_strnstr2()
{
	signal(SIGSEGV, handler);
	ft_strnstr("dfdfddf", 0, 3);
	exit(1);
}

void strnstr_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strnstr1();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void strnstr_segv_test2()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strnstr2();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	strnstr_t(char *big, char *little, size_t len)
{
	if (ft_strnstr(big, little, len) == strnstr(big, little, len))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}


void	strnstr_test()
{
	char	*tab[10];
	int		len[10];
	char	*str;

	str = "strnstr: ";
	write(1, str, strlen(str));
	strnstr_segv_test();
	strnstr_segv_test2();
	tab[0] = "";
	tab[1] = " ";
	tab[2] = "id";
	tab[3] = "ex\0, mollis";
	tab[4] = "Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla \xff\xfe pulvinar eu. Fusce \x01\x02 fermentum sem. Cras\
volutpat, \xfe\xff eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis \xff\xff purus. Mauris magna ex, mollis \x02\x01 suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.";
	tab[5] = "\xfe\xff";
	tab[6] = "\x02\x01";
	tab[7] = "\x01\x02";
	tab[8] = "\xff\xff";
	tab[9] = "\xff\xfe";
	for (int i = 0; i < 10; i++)
		len[i] = strlen(tab[i]);
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			for (int j = 0; j < 10; j++)
				strnstr_t(tab[i], tab[k], len[j]);
		}
	}
	printf("\n");
}