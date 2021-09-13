#include "../inc/push_swap.h"

static void	push_node(t_node **src, t_node **dest)
{
	t_node *new_node;

	new_node = (*src);
	if (*src == NULL)
		return ;
	(*src) = (*src)->next;
	new_node->next = (*dest);
	(*dest) = new_node;
}

void		push(t_node **a, t_node **b, enum e_ins_info ins_info)
{
	static char	*instructions[3] = {"pa\n", "pb\n", ""};

	if (ins_info == e_INS_A)
		push_node(b, a);
	if (ins_info == e_INS_B)
		push_node(a, b);
	ft_putstr_fd(instructions[ins_info], 1);
}
