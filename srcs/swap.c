#include "../inc/push_swap.h"

static void	swap_nodes(t_node **head)
{
	int			tmp;
	t_node	*ptr;

	if (!head || (*head)->next == NULL)
		return ;
	ptr = *head;
	tmp = ptr->data;
	ptr->data = ptr->next->data;
	ptr->next->data = tmp;
}

void		swap(t_node **a, t_node **b, enum e_ins_info ins_info)
{
	static char	*instructions[3] = {"sa\n", "sb\n", "ss\n"};

	if (ins_info == e_INS_A || ins_info == e_INS_AB)
		swap_nodes(a);
	if (ins_info == e_INS_B || ins_info == e_INS_AB)
		swap_nodes(b);
	ft_putstr_fd(instructions[ins_info], 1);
}
