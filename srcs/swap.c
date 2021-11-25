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
** Outputs the operation.
*/
void	swap(t_node **head, enum e_stack_id stack_id)
{
	int		tmp;
	t_node	*ptr;
	char	*message[2];

	message[0] = "sa\n";
	message[1] = "sb\n";
	if (!head || (*head)->next == NULL)
		return ;
	ptr = *head;
	tmp = ptr->data;
	ptr->data = ptr->next->data;
	ptr->next->data = tmp;
	ft_putstr_fd(message[stack_id], 1);
}
