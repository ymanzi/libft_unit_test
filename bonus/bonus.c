#include "../srcs/ft_libft_test.h"

void	fct(void *elem)
{
	elem = ft_strdup("YES");
	// free(buf->content);
	// elem = "YES";
}

void	*fct2(void *elem)
{
	(void)elem;
	return strdup("YES");
}

int	main()
{
	char	*tab[11];
	int		len[11];

	printf("" YELLOW "~~~~~~~ BONUS TEST ~~~~~~~\n" RESET "");
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
	tab[6] = "\xfe\xff";
	tab[7] = "\x02\x01";
	tab[8] = "\x01\x02";

	t_list *list;
	for (int i = 4; i > 0; i--)
	{
		t_list *elem = ft_lstnew(ft_strdup(tab[i]));
		ft_lstadd_front(&list, elem);
	}
	for (int i = 5; i < 9; i++)
	{
		t_list *elem = ft_lstnew(ft_strdup(tab[i]));
		ft_lstadd_back(&list, elem);
	}
	if (ft_lstsize(list) == 8)
		printf("" GREEN "[LSTSIZE OK] " RESET "");
	else
		printf("" RED "[LSTSIZE K.O] " RESET "");
	t_list *elem = ft_lstlast(list);
	if (!strcmp((char*)elem->content, tab[8]))
		printf("" GREEN "[LSTLAST OK] " RESET "");
	else
		printf("" RED "[LSTLAST K.O] " RESET "");
	if (!strcmp(list->content, ""))
		printf("" GREEN "[ADDFRONT - ADDBACK OK] " RESET "");
	else
		printf("" RED "[ADDFRONT - ADDBACK K.O] " RESET "");
	int test = 1;
	t_list *new_list = ft_lstmap(list, fct2, free);
	for (t_list *it = new_list; it != 0; it = it->next)
	{
		if (strcmp(it->content, "YES"))
			test = 0;
	}
	if (test)
		printf("" GREEN "[LSTMAP OK] " RESET "");
	else
		printf("" RED "[LSTMAP K.O] " RESET "");
	ft_lstclear(&list, free);
	ft_lstclear(&new_list, free);
	t_list *el = ft_lstnew(strdup("YES"));
	ft_lstdelone(el, free);
	printf("\n");
	system("leaks bonus_test");
	return (0);
}