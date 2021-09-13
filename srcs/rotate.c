#include "../inc/push_swap.h"

static void	rotate_stack(t_node **head)
{
	int		head_data;
	t_node	*ptr;

	ptr = (*head);
	head_data = (*head)->data;
	if (!head || (*head)->next == NULL)
		return ;
	while (ptr->next != NULL)
	{
		ptr->data = ptr->next->data;
		ptr = ptr->next;
	}
	ptr->data = head_data;
}

void		rotate(t_node **a, t_node **b, enum e_ins_info ins_info)
{
	static char	*instructions[3] = {"ra\n", "rb\n", "rr\n"};

	if (ins_info == e_INS_A || ins_info == e_INS_AB)
		rotate_stack(a);
	if (ins_info == e_INS_B || ins_info == e_INS_AB)
		rotate_stack(b);
	ft_putstr_fd(instructions[ins_info], 1);
}
