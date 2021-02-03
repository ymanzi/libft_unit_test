#include "ft_libft_test.h"

char    *strjoin(char const *s1, char const *s2)
{
        int             size_s1;
        int             size_s2;
        char    *ptr;
        int             i;
        int             j;

        i = 0;
        j = 0;
        if (s1 == 0 || s2 == 0)
                return (0);
        size_s1 = ft_strlen(s1);
        size_s2 = ft_strlen(s2);
        if (!(ptr = (char*)malloc(sizeof(*ptr) * (size_s1 + size_s2 + 1))))
                return (0);
        while (*(s1 + i))
                ptr[j++] = *(s1 + i++);
        i = 0;
        while (*(s2 + i))
                ptr[j++] = *(s2 + i++);
        ptr[j] = '\0';
        return (ptr);
}


void segv_test_strjoin1()
{
	signal(SIGSEGV, handler);
	ft_strjoin("lol", 0);
	exit(1);
}

void segv_test_strjoin2()
{
	char	buff[100];

	signal(SIGSEGV, handler);
	ft_strjoin(0, "lol");
	exit(1);
}

void strjoin_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strjoin1();
	wait(&status);
	if (!status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void strjoin_segv_test2()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strjoin2();
	wait(&status);
	if (!status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	strjoin_t(char *s1, char *s2)
{
	if (!strcmp(ft_strjoin(s1, s2), strjoin(s1, s2)))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}


void	strjoin_test()
{
	char	*tab[11];
	int		len[11];
	char	*str;

	printf("" YELLOW "~~~~~~~ STRJOIN TEST ~~~~~~~\n" RESET "");
	strjoin_segv_test();
	strjoin_segv_test2();
	tab[1] = "";
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
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
			strjoin_t(tab[i], tab[j]);
	}
	printf("\n");
}