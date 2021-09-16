/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:54:38 by challeau          #+#    #+#             */
/*   Updated: 2021/09/16 11:54:38 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Frees a stack.
*/
void	ft_memdel_stack(t_node *head)
{
	t_node	*ptr;

	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
		ptr = NULL;
	}
}

/*
** Outputs the content of the stack to stdout.
*/
void	print_stack(t_node *head)
{
	while (head != NULL)
	{
		ft_putnbr_fd(head->data, 1);
		ft_putstr_fd("  ", 1);
		head = head->next;
	}
	ft_putstr_fd("\n", 1);
}

/*
** Returns the ammount of nodes in the stack.
*/
uint8_t	stack_len(t_node *head)
{
	uint8_t	len;
	t_node	*ptr;

	len = 0;
	ptr = head;
	while (ptr->next != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	len++;
	return (len);
}
