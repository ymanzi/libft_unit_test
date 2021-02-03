
#include "ft_libft_test.h"

void segv_test_bzero()
{
	signal(SIGSEGV, handler);
	ft_bzero(0, 5);
	exit(1);
}

void bzero_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_bzero();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

int bzero_t(void *b, size_t len)
{
	int i;
	char *str;

	i = 0;
	str = (char*)b;
	ft_bzero(b, len);
	while (*str++)
		i++;
	return (i);
}

void	bzero_test()
{
	char	buf[100];

	printf("" YELLOW "~~~~~~~ BZERO TEST ~~~~~~~\n" RESET "");
	bzero_segv_test();
	memset(buf, 'A', 42);
	if (bzero_t(buf, 5))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	memset(buf, 'A', 42);
	bzero_t(buf + 42, 5);
	if (buf[41] != 'A' || buf[42])
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	printf("\n");
}