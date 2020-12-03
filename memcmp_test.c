#include "ft_libft_test.h"

void segv_test_memcmp1()
{
	signal(SIGSEGV, handler);
	ft_memcmp(0, "lol", 3);
	exit(1);
}

void segv_test_memcmp2()
{
	char	buff[100];

	signal(SIGSEGV, handler);
	ft_memcmp("str", 0, 3);
	exit(1);
}

void memcmp_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_memcmp1();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void memcmp_segv_test2()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_memcmp2();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	memcmp_t(char *s1, char *s2, size_t n)
{
	if (ft_memcmp(s1, s2, n) == memcmp(s1, s2, n))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	memcmp_test()
{
	char	buff[100];
	char	*str;
	char	*tab[11];

	bzero(buff, 100);
	str = "memcmp: ";
	write(1, str, strlen(str));
	memcmp_segv_test();
	memcmp_segv_test2();
	
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
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			int len;

			len = (strlen(tab[i]) > strlen(tab[j]) ? strlen(tab[j]): strlen(tab[i]));
			memcmp_t(tab[i], tab[j], len);
		}
	}
	printf("\n");
}