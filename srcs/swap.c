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
void	swap(t_node **head, char *str)
{
	int		tmp;
	t_node	*ptr;

	if (!head || (*head)->next == NULL)
		return ;
	ptr = *head;
	tmp = ptr->data;
	ptr->data = ptr->next->data;
	ptr->next->data = tmp;
	ft_putstr_fd(str, 1);
}
