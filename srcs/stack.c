#include "../inc/push_swap.h"

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
