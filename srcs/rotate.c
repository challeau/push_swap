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
void	rotate(t_node **head, enum e_stack_id stack_id)
{
	int		head_data;
	t_node	*ptr;
	char	*message[2];

	message[0] = "ra\n";
	message[1] = "rb\n";
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
	ft_putstr_fd(message[stack_id], 1);
}
