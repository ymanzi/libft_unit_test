#include "ft_libft_test.h"

void segv_test_atoi1()
{
	signal(SIGSEGV, handler);
	ft_atoi(0);
	exit(1);
}

void atoi_segv_test()
{
	int pid;
	int	status;

	pid = fork();
	if (!pid)
		segv_test_atoi1();
	wait(&status);
	if (status)
		printf("" RED "[SEGV K.O] " RESET "");
	else
		printf("" GREEN "[SEGV OK] " RESET "");
}

void	atoi_t(char *s1)
{
	if (ft_atoi(s1) == atoi(s1))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[K.O] " RESET "");
}

void	atoi_test()
{
	char	*str;

	str = "atoi: ";
	write(1, str, strlen(str));
	atoi_segv_test();
	atoi_t("");
	atoi_t("+-+1");
	atoi_t("+ -+5 ");
	atoi_t("+-0+5");
	atoi_t("\f0+-5");
	atoi_t("\f+-569");
	atoi_t("+-+565\f054");
	atoi_t("+-+00000565");
	atoi_t("\f\t -+-----++++6540000");
	atoi_t("\f\t +\t485");
	atoi_t("    -6565 6594");
	atoi_t("-2147483648");
	atoi_t("-2147484649");
	atoi_t("2147483647");
	atoi_t("2147484647");
	atoi_t("4548478646489885464642319879784564");
	printf("\n");
}