#include "ft_libft_test.h"

void segv_test_memccpy1()
{
	signal(SIGSEGV, handler);
	ft_memccpy(0, "abcdef", 'A', 4);
	exit(1);
}

void segv_test_memccpy2()
{
	char	buff[100];

	signal(SIGSEGV, handler);
	ft_memccpy(buff, 0, 'A', 3);
	exit(1);
}

void memccpy_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_memccpy1();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void memccpy_segv_test2()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_memccpy2();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}


void	memccpy_test()
{
	char	buff[100];
	char	*str;
	char	*ret;

	bzero(buff, 100);
	str = "memccpy: ";
	write(1, str, strlen(str));
	memccpy_segv_test();
	memccpy_segv_test2();
	ret = ft_memccpy(buff, "abcdef", 'g',   6);
	if (!strcmp(buff, "abcdef") && !ret)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	ret = ft_memccpy(buff, "abcdef", 'e', 4);
	if (!strcmp(buff, "abcdef") && !ret)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	ret = ft_memccpy(buff, "abcdef", 'c', 3);
	if (!strcmp(buff, "abcdef") && !strcmp(ret, "def"))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	ret = ft_memccpy(buff, "abcdef", 'c', 3);
	if (!strcmp(buff, "abcdef") && !strcmp(ret, "def"))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	ret = ft_memccpy(buff, "abcdef", 0, 10);
	if (!strcmp(buff, "abcdef") && !(*ret))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	printf("\n");
}