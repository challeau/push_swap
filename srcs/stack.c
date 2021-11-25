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
** Returns the ammount of nodes in the stack.
*/
int	stack_len(t_node *head)
{
	int		len;
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

/*
** Frees the stack.
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
** Returns true if the stack is sorted, false if it isnt.
*/
bool	stack_is_sorted(t_node *head)
{
	int		tmp;
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
** Manipulates the stack pointed by a until the first node holds
** the smallest data.
*/
void	stack_pointer_to_min(t_node **a)
{
	int	min;

	min = stack_min(*a);
	if (get_node_id(*a, min) < stack_len(*a) / 2)
	{
		while ((*a)->data != min)
			rotate(a, e_STACK_A);
	}
	else
	{
		while ((*a)->data != min)
			rev_rotate(a, e_STACK_A);
	}
}

/*
** Outputs the content of the stack to stdout.
*/
void	print_stacks(t_node *a, t_node *b)
{
	ft_putstr_fd("---------------------------------\n", 1);
	while (a != NULL)
	{
		ft_putnbr_fd(a->data, 1);
		ft_putstr_fd("  ", 1);
		a = a->next;
	}
	ft_putstr_fd("\n", 1);
	while (b != NULL)
	{
		ft_putnbr_fd(b->data, 1);
		ft_putstr_fd("  ", 1);
		b = b->next;
	}
	ft_putstr_fd("\n---------------------------------\n", 1);
}
