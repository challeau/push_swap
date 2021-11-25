/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:54:29 by challeau          #+#    #+#             */
/*   Updated: 2021/09/16 11:54:29 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Frees the stack, outputs an error message and exits.
*/
void	error(t_node *head)
{
	if (head)
		ft_memdel_stack(head);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}


/*
** Manipulates the stack pointed by a until the first node holds the smallest data.
*/
void	stack_pointer_to_min(t_node **a)
{
	int	min;

	min= stack_min(*a);
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
** Returns the stack's minimum value that is greater than prev_min. 
*/
int	get_next_min(t_node *head, int prev_min)
{
	int	new_min = INT_MAX;
	t_node *ptr = head;

	while (ptr != NULL)
	{
		if (ptr->data < new_min && ptr->data > prev_min)
			new_min = ptr->data;
		ptr = ptr->next;
	}
	if (prev_min == INT_MIN && new_min == INT_MAX)
		return(prev_min);
	return (new_min);
}

/*
** Returns the index of the node that holds node_data in the stack.
*/
int	get_node_id(t_node *head, int node_data)
{
	int		index;
	t_node	*ptr;

	index = 0;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == node_data)
			return (index);
		index++;
		ptr = ptr->next;
	}
	return (index);
}
