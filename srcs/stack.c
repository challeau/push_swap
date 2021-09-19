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

int	peek(t_node *head)
{
	if (head == NULL)
		return (INT_MIN);
	return (head->data);
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
** Returns true if the stack is sorted, false if it isnt.
*/
bool	stack_is_sorted(t_node *head)
{
	int	tmp;
	t_node	*ptr;

	tmp = INT_MIN;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data < tmp)
			return (false);
		tmp = ptr->data;
		ptr = ptr->next;
	}
	return (true);
}

/*
** Returns the ammount of nodes in the stack.
*/
int	stack_len(t_node *head)
{
	int	len;
	t_node	*ptr;

	len = 0;
	ptr = head;
	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}
