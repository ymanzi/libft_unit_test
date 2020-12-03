#include "ft_libft_test.h"

void segv_test_memset()
{
	signal(SIGSEGV, handler);
	ft_memset(0, 12, 5);
	exit(1);
}

void memset_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_memset();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

int memset_t(void *b, int c, size_t len)
{
	int i;
	char *str;

	i = 0;
	str = (char*)b;
	ft_memset(b, c, len);
	while (*str++)
		i++;
	return (i);
}

void	memset_test()
{
	char	buf[100];

	write(1, "memset: ", 8);
	memset_segv_test();
	if (memset_t(buf, 0, 42))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	if (memset_t(buf, 'A', 42) != 42)
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	printf("\n");
}