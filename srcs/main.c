#include "../inc/push_swap.h"



int	main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	if (ac < 2)
		error(NULL, NULL);
	a = get_stack(ft_strptrdup(av + 1));
	b = NULL;
	/* print_stack(a); */
	/* print_stack(b); */
	/* rev_rotate(&a, &b, e_INS_A); */
	/* push(&a, &b, e_INS_B); */
	/* push(&a, &b, e_INS_B); */
	/* push(&a, &b, e_INS_B); */
	/* rotate(&a, &b, e_INS_AB); */
	print_stack(a);
	/* print_stack(b); */
	ft_memdel_stack(a);
	/* ft_memdel_stack(b); */
	return (0);
}
