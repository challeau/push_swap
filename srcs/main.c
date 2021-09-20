/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:48:04 by challeau          #+#    #+#             */
/*   Updated: 2021/09/16 11:48:04 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	smol_sort(t_node **a, t_node **b, int stack_size);

int	node_index(t_node *head, int node_data)
{
	int	i;
	t_node	*ptr;

	i = 0;
	ptr = head;
	while(ptr != NULL)
	{
		if (ptr->data > node_data)
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void	sort_4_5(t_node **a, t_node **b, int stack_size)
{
	int	index;

	while (stack_len(*a) > 3)
		push(a, b, e_INS_B);
	if (stack_is_sorted(*a) == false)
		smol_sort(a, b, 3);
	while ((*b) != NULL)
	{
		index = node_index(*a, (*b)->data);
		int i = index;
		if (i < stack_size / 2)
		{
			while (i > 0)
			{
				rotate(a, b, e_INS_A);
				i--;
			}
		}
		else
		{
			int pos = stack_len(*a) - index;
			while (pos > 0)
			{
				rev_rotate(a, b, e_INS_A);
				pos--;
			}
		}
		push(a, b, e_INS_A);
		if (index < stack_size / 2)
		{
			while (index > 0)
			{
				rev_rotate(a, b, e_INS_A);
				index--;
			}
		}
		else
		{
			int p = stack_len(*a) - index ;
			while (p > 0)
			{
				rotate(a, b, e_INS_A);
				p--;
			}
		}
	}
}

/*
** Sorts stack of size 2 or 3.
*/
void	smol_sort(t_node **a, t_node **b, int stack_size)
{
	int	first;
	int	second;
	int	last;

	first = (*a)->data;
	second = (*a)->next->data;
	if (stack_size == 2 && first > second)
			swap(a, b, e_INS_A);
	else if (stack_size == 3)
	{
		last = (*a)->next->next->data;
		if (first < last || (first > second && second > last))
		{
			swap(a, b, e_INS_A);
			first = (*a)->data;
			second = (*a)->next->data;
		}
		if (first > second)
			rotate(a, b, e_INS_A);
		if (second > last)
			rev_rotate(a, b, e_INS_A);
	}
	else
		sort_4_5(a, b, stack_size);
}

/* stack a has the items to sort, stack b is a work stack. */
int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int	stack_size;

	if (ac < 2 || *av[1] == '\0')
		error(NULL);
	a = get_stack(av + 1);
	b = NULL;
	stack_size = stack_len(a);
	if (stack_is_sorted(a) == false)
	{
		if (stack_size <= 5)
			smol_sort(&a, &b, stack_size);
	}
//	print_stacks(a, NULL);
	ft_memdel_stack(a);
	ft_memdel_stack(b);
	return (0);
}
