#include "ft_libft_test.h"

void segv_test_strlcpy1()
{
	signal(SIGSEGV, handler);
	ft_strlcpy(0, "abcdef", 4);
	exit(1);
}

void segv_test_strlcpy2()
{
	char	buff[100];

	signal(SIGSEGV, handler);
	ft_strlcpy(buff, 0, 3);
	exit(1);
}

void strlcpy_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strlcpy1();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void strlcpy_segv_test2()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strlcpy2();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	strlcpy_t(char *src, size_t len)
{
	char	bo[1000];
	char	bft[1000];
	char	*str;

	bzero(bo, 1000);
	bzero(bft, 1000);
	str = "Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.";
	strlcat(bo, str, sizeof(bo));
	strlcat(bft, str, sizeof(bft));
	if (ft_strlcpy(bft, src, len) == strlcpy(bo, src, len) && !strcmp(bft, bo))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}


void	strlcpy_test()
{
	char	*tab[11];
	int		len[11];
	char	*str;

	printf("" YELLOW "~~~~~~~ STRLCPY TEST ~~~~~~~\n" RESET "");
	strlcpy_segv_test();
	strlcpy_segv_test2();
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
		len[i] = strlen(tab[i]);
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			strlcpy_t(tab[i], len[j]);
	}
	printf("\n");
}