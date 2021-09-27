/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:08:17 by challeau          #+#    #+#             */
/*   Updated: 2021/09/16 15:08:17 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Moves down the nodes of the stack by 1.
** Outputs the operation.
*/
void	rev_rotate(t_node **head, char *str)
{
	t_node	*ptr;
	t_node	*new_node;

	new_node = NULL;
	if (!head || (*head)->next == NULL)
		return ;
	ptr = (*head);
	while (ptr->next != NULL)
		add_node_back(&new_node, pop(&ptr));
	add_node_front(&new_node, pop(&ptr));
	(*head) = new_node;
	ft_putstr_fd(str, 1);
}
