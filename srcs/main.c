#include "../inc/push_swap.h"

t_node	*get_stack(char **args)
{
	int i = 1;
	t_node	*new_stack = NULL;

	while (args[i])
	{
		add_node_back(&new_stack, ft_atoi(args[i]));
		i++;
	}
	return (new_stack);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	t_node *a = get_stack(av);
	t_node *b = NULL;

	print_stack(a);
	rev_rotate(&a, &b, e_INS_A);
	print_stack(a);
	rotate(&a, &b, e_INS_A);
	print_stack(a);
	ft_memdel_stack(a);
	return (0);
}
