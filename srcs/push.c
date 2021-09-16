/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:07:09 by challeau          #+#    #+#             */
/*   Updated: 2021/09/16 15:07:09 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Pushes a node from stack src to stack dest.
*/
static void	push_node(t_node **src, t_node **dest)
{
	t_node	*new_node;

	new_node = (*src);
	if (*src == NULL)
		return ;
	(*src) = (*src)->next;
	new_node->next = (*dest);
	(*dest) = new_node;
}

/*
** Pushes a node from stack a to stack b or from stack b to stack a
** (depending on ins_info). Outputs the operation.
*/
void	push(t_node **a, t_node **b, enum e_ins_info ins_info)
{
	static char	*instructions[3] = {"pa\n", "pb\n", ""};

	if (ins_info == e_INS_A)
		push_node(b, a);
	if (ins_info == e_INS_B)
		push_node(a, b);
	ft_putstr_fd(instructions[ins_info], 1);
}
