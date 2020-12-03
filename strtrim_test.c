#include "ft_libft_test.h"

void segv_test_strtrim1()
{
	signal(SIGSEGV, handler);
	ft_strtrim("lol", 0);
	exit(1);
}

void segv_test_strtrim2()
{
	char	buff[100];

	signal(SIGSEGV, handler);
	ft_strtrim(0, "lol");
	exit(1);
}

void strtrim_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strtrim1();
	wait(&status);
	if (!status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void strtrim_segv_test2()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_strtrim2();
	wait(&status);
	if (!status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	strtrim_t(char *s1, char *s2, char *s3)
{
	if (!strcmp(ft_strtrim(s1, s2), s3))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	strtrim_test()
{
	char	*tab[11];
	int		len[11];
	char	*str;

	str = "strtrim: ";
	write(1, str, strlen(str));
	strtrim_segv_test();
	strtrim_segv_test2();
	tab[0] = "mmeerrooll adipiscing lloorreemm";
	strtrim_t(tab[0], "lorem ", "adipiscing");
	strtrim_t(tab[0], "lorem", " adipiscing ");
	strtrim_t(tab[0], "orem", "ll adipiscing ll");
	strtrim_t(tab[0], "rem", "ooll adipiscing lloo");
	strtrim_t(tab[0], "m ", "eerrooll adipiscing lloorree");
	strtrim_t(tab[0], "lore ", "mmeerrooll adipiscing lloorreemm");
	strtrim_t(tab[0], "", "mmeerrooll adipiscing lloorreemm");
	printf("\n");
}