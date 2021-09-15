#include "../inc/push_swap.h"

void	print_stack(t_node *head)
{
	while (head != NULL)
	{
		ft_putnbr_fd(head->data, 1);
		ft_putstr_fd("  ", 1);
		head= head->next;
	}
	ft_putstr_fd("\n", 1);
}

void	error(t_node *head, char **args)
{
	if (head)
		ft_memdel_stack(head);
	if (args)
		ft_memdel_strptr(args);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}