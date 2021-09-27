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
** Moves up the nodes of the stack by 1.
** Outputs the operation.
*/
void	rotate(t_node **head, char *str)
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
	ft_putstr_fd(str, 1);
}
