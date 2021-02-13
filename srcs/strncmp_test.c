#include "ft_libft_test.h"

void segv_test_strncmp1()
{
	signal(SIGSEGV, handler);
	ft_strncmp(0, "lol", 3);
	exit(1);
}

void segv_test_strncmp2()
{
	char	buff[100];

	signal(SIGSEGV, handler);
	ft_strncmp("str", 0, 3);
	exit(1);
}

void strncmp_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strncmp1();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void strncmp_segv_test2()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strncmp2();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	strncmp_t(char *s1, char *s2, size_t n)
{
	int check = 1;
	int ret_r = strncmp(s1, s2, n);
	int ret_ft = ft_strncmp(s1, s2, n);
	if ( ret_r == 0 && ret_ft != 0)
		check = 0;
	else if ((ret_r * ret_ft) < 0)
		check = 0;
	if (check)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	strncmp_test()
{
	char	buff[100];
	char	*str;
	char	*tab[11];

	bzero(buff, 100);
	printf("" YELLOW "~~~~~~~ STRNCMP TEST ~~~~~~~\n" RESET "");
	strncmp_segv_test();
	strncmp_segv_test2();
	
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

			len = (strlen(tab[i]) < strlen(tab[j]) ? strlen(tab[j]): strlen(tab[i]));
			strncmp_t(tab[i], tab[j], len);
		}
	}
	printf("\n");
}
