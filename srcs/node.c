#include "../inc/push_swap.h"

bool	add_node_after(t_node **prev_node, int data)
{
	t_node *new_node;

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

bool	add_node_back(t_node **head, int data)
{
	t_node *new_node;
	t_node *ptr;

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

bool	add_node_front(t_node **head, int data)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (false);
	new_node->data = data;
	new_node->next = (*head);
	(*head) = new_node;
	return (true);
}

int	pop(t_node **head)
{
	int	res;
	t_node	*ptr;

	if (*head == NULL)
		return (0);
	{
		ptr = (*head);
		res = ptr->data;
		(*head) = ptr->next;
		free(ptr);
	}
	return (res);
}
