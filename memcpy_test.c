#include "ft_libft_test.h"

void segv_test_memcpy1()
{
	signal(SIGSEGV, handler);
	ft_memcpy(0, "lol", 4);
	exit(1);
}

void segv_test_memcpy2()
{
	char	buff[100];

	signal(SIGSEGV, handler);
	ft_memcpy(buff, 0, 3);
	exit(1);
}

void memcpy_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_memcpy1();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void memcpy_segv_test2()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_memcpy2();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}


void	memcpy_test()
{
	char	buff[100];
	char	*str;

	bzero(buff, 100);
	str = "memcpy: ";
	write(1, str, strlen(str));
	memcpy_segv_test();
	memcpy_segv_test2();
	ft_memcpy(buff, "Lol", 4);
	if (strcmp(buff, "Lol"))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	ft_memcpy(buff + 3, "Lol", 4);
	if (strcmp(buff + 3, "Lol"))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	ft_memcpy(buff + 3, "Lol", 0);
	if (strcmp(buff + 3, "Lol"))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	ft_memcpy(buff + 50, "Lol", 3);
	if (strcmp(buff + 50, "Lol"))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	printf("\n");
}