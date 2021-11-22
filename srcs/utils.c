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
** Assigns the minimum and maximum values in the stack.
*/
void	find_data_limits(t_node *head, long *min, long *max)
{
	t_node	*ptr;

	*min = INT_MAX;
	*max = INT_MIN;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data < *min)
			*min = ptr->data;
		if (ptr->data > *max)
			*max = ptr->data;
		ptr = ptr->next;
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
