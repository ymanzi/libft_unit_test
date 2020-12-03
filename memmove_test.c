#include "ft_libft_test.h"

void segv_test_memmove1()
{
	signal(SIGSEGV, handler);
	ft_memmove(0, "abcdef", 4);
	exit(1);
}

void segv_test_memmove2()
{
	char	buff[100];

	signal(SIGSEGV, handler);
	ft_memmove(buff, 0, 3);
	exit(1);
}

void memmove_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_memmove1();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void memmove_segv_test2()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_memmove2();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}


void	memmove_test()
{
	char	buff[100];
	char	*str;
	char	*ret;

	bzero(buff, 100);
	str = "memmove: ";
	write(1, str, strlen(str));
	memmove_segv_test();
	memmove_segv_test2();
	ft_memmove(buff, "abcdef", 6);
	if (!strcmp(buff, "abcdef"))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	ret = ft_memmove(buff + 1, buff + 1, 5);
	if (!strcmp(buff, "abcdef") && !strcmp(buff + 1, ret))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	ret = ft_memmove(buff + 1, buff, 5);
	if (!strcmp(buff, "aabcde") && !strcmp(buff + 1, ret))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	ret = ft_memmove(buff, "abcdef", 3);
	if (!strcmp(buff, "abccde") && !strcmp(buff, ret))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	printf("\n");
}