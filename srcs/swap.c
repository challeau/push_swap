/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:09:55 by challeau          #+#    #+#             */
/*   Updated: 2021/09/16 15:09:55 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Swaps the first two nodes of the stack.
*/
static void	swap_nodes(t_node **head)
{
	int		tmp;
	t_node	*ptr;

	if (!head || (*head)->next == NULL)
		return ;
	ptr = *head;
	tmp = ptr->data;
	ptr->data = ptr->next->data;
	ptr->next->data = tmp;
}

/*
** Swaps the first two nodes of stack a, b, or both (depending on ins_info).
** Outputs the operation.
*/
void	swap(t_node **a, t_node **b, enum e_ins_info ins_info)
{
	static char	*instructions[3] = {"sa\n", "sb\n", "ss\n"};

	if (ins_info == e_INS_A || ins_info == e_INS_AB)
		swap_nodes(a);
	if (ins_info == e_INS_B || ins_info == e_INS_AB)
		swap_nodes(b);
	ft_putstr_fd(instructions[ins_info], 1);
}
