#include "ft_libft_test.h"

void segv_test_memchr()
{
	signal(SIGSEGV, handler);
	ft_memchr(0, 12, 5);
	exit(1);
}

void memchr_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_memchr();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	memchr_test()
{
	char	buf[100];
	char	*ret;

	printf("" YELLOW "~~~~~~~ MEMCHR TEST ~~~~~~~\n" RESET "");
	memchr_segv_test();
	memcpy(buf, "abcdef", 6);
	if (ft_memchr(buf, 0, 3))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	if (!ft_memchr(buf, 0, 7))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	if (ft_memchr(buf, '\t', 6))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	if (ft_memchr(buf, 'd', 3))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	if ((ret = ft_memchr(buf, 'd', 6)) && !strcmp(ret, "def"))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
	printf("\n");
}