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
** Outputs the operation.
*/
void	push(t_node **src, t_node **dst, enum e_stack_id dst_id)
{
	t_node	*new_node;
	char	*message[2];

	message[0] = "pa\n";
	message[1] = "pb\n";
	new_node = (*src);
	if (*src == NULL)
		return ;
	(*src) = (*src)->next;
	new_node->next = (*dst);
	(*dst) = new_node;
	ft_putstr_fd(message[dst_id], 1);
}
