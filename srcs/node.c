/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:49:39 by challeau          #+#    #+#             */
/*   Updated: 2021/09/16 11:49:39 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Creates a new node containing the data and inserts it at the end of the stack.
** Returns true upon success.
*/
bool	add_node_back(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*ptr;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (false);
	ptr = (*head);
	new_node->data = data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		(*head) = new_node;
		return (true);
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new_node;
	return (true);
}

/*
** Creates a new node containing the data and inserts it at the begining of
** the stack. Returns true upon success.
*/
bool	add_node_front(t_node **head, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (false);
	new_node->data = data;
	new_node->next = (*head);
	(*head) = new_node;
	return (true);
}

/*
** Creates a new node containing data and inserts it after the node prev_node.
** Returns true upon success.
*/
bool	add_node_after(t_node **prev_node, int data)
{
	t_node	*new_node;

	if (*prev_node == NULL)
		return (false);
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (false);
	new_node->data = data;
	new_node->next = (*prev_node)->next;
	(*prev_node)->next = new_node;
	return (true);
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

/*
** Returns the index where the node containing node_data belongs.
*/
int	get_node_insertion_id(t_node *head, int node_data)
{
	int		i;
	t_node	*ptr;

	i = 0;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data > node_data)
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (i);
}
