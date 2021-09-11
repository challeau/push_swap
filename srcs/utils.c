#include "../inc/push_swap.h"

void	print_stack(t_node *node)
{
	while (node != NULL)
	{
		printf("%d  ", node->data);
		node = node->next;
	}
	printf("\n");
}