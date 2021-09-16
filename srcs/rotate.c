/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:08:54 by challeau          #+#    #+#             */
/*   Updated: 2021/09/16 15:08:54 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Performs a rotation on the stack.
*/
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

/*
** Moves up the nodes of stack a, b, or both (depending on ins_info) by 1.
** Outputs the operation.
*/
void	rotate(t_node **a, t_node **b, enum e_ins_info ins_info)
{
	static char	*instructions[3] = {"ra\n", "rb\n", "rr\n"};

	if (ins_info == e_INS_A || ins_info == e_INS_AB)
		rotate_stack(a);
	if (ins_info == e_INS_B || ins_info == e_INS_AB)
		rotate_stack(b);
	ft_putstr_fd(instructions[ins_info], 1);
}
