#include "ft_libft_test.h"


char	fct(unsigned int i, char c)
{
	return (int)c + i;
}

char	*strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sptr;
	int		index;

	if (!s || !f)
		return (NULL);
	if (!(sptr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	index = 0;
	while (s[index])
	{
		sptr[index] = f(index, s[index]);
		++index;
	}
	sptr[index] = '\0';
	return (sptr);
}


void segv_test_strmapi1()
{
	signal(SIGSEGV, handler);
	ft_strmapi("lol", 0);
	exit(1);
}

void segv_test_strmapi2()
{
	char	buff[100];

	signal(SIGSEGV, handler);
	ft_strmapi(0, fct);
	exit(1);
}

void strmapi_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strmapi1();
	wait(&status);
	if (!status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void strmapi_segv_test2()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strmapi2();
	wait(&status);
	if (!status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	strmapi_t(char *s1)
{
	if (!strcmp(ft_strmapi(s1, fct), strmapi(s1, fct)))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}


void	strmapi_test()
{
	char	*tab[11];
	int		len[11];
	char	*str;

	printf("" YELLOW "~~~~~~~ STRMAPI TEST ~~~~~~~\n" RESET "");
	strmapi_segv_test();
	strmapi_segv_test2();
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
	for (int i = 1; i < 6; i++)
		strmapi_t(tab[i]);
	printf("\n");
}