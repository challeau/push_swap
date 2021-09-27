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
void	push(t_node **src, t_node **dest, char *str)
{
	t_node	*new_node;

	new_node = (*src);
	if (*src == NULL)
		return ;
	(*src) = (*src)->next;
	new_node->next = (*dest);
	(*dest) = new_node;
	ft_putstr_fd(str, 1);
}
