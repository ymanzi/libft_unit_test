#include "ft_libft_test.h"

void segv_test_substr1()
{
	signal(SIGSEGV, handler);
	ft_substr(0, 0, 4);
	exit(1);
}

void substr_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_substr1();
	wait(&status);
	if (!status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	substr_test()
{
	char	*buff;
	char	*str;

	printf("" YELLOW "~~~~~~~ SUBSTR TEST ~~~~~~~\n" RESET "");
	substr_segv_test();
	buff = "un jour dans la prairie";	
	if (strcmp(ft_substr(buff, 0, 3), "un "))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	if (strcmp(ft_substr(buff, 42, 3), ""))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	if (strcmp(ft_substr(buff, 0, 46), buff))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	if (strcmp(ft_substr(buff, 5, 6), "ur dan"))
		printf("" RED "[K.O] " RESET "");
	else
		printf("" GREEN "[OK] " RESET "");
	printf("\n");
}