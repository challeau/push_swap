/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:33:28 by challeau          #+#    #+#             */
/*   Updated: 2021/09/20 16:33:28 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	max(t_node *head)
{
	int	max;
	t_node	*ptr;

	max = INT_MIN;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data > max)
			max = ptr->data;
		ptr = ptr->next;
	}
	return (max);
}

void	partition(t_node **a, t_node **b, int pivot)
{
	char	*ins = ft_strdup("");
	t_node *ptr = (*a);

	while (ptr != NULL && max(ptr) > pivot)
	{
		if (ptr->data > pivot)
			ins = ft_add_char(ins, 'p');
		else
			ins = ft_add_char(ins, 'r');
		ptr = ptr->next;
	}
	for (int i = 0 ; ins[i] ; i++)
	{
		if (ins[i] == 'p')
			push(a, b, "pb\n");
		else if (ins[i] == 'r')
			rotate(a, "ra\n");
	}
	ft_memdel(ins);
}

int	avg(t_node *a)
{
	t_node *ptr;
	int sum;

	sum = 0;
	ptr = a;
	while (ptr != NULL)
	{
		sum += ptr->data;
		ptr = ptr->next;
	}
	return (sum / stack_len(a));
}

void	sort_big_stack(t_node **a, t_node **b)
{
	long	med_data;
	int	min;

	min = INT_MIN;
	while (stack_len(*a) > 5)
	{
		med_data = avg(*a);
		partition(a, b, med_data);
	}
	if (stack_is_sorted(*a) == false)
		sort_small_stack(a, b, stack_len(*a));
	while (*b)
	{
		min = get_next_min(*b, min);
		while ((*b)->data != min)
		{
			if (node_id(*b, min) <= stack_len(*b) / 2)
				rotate(b, "rb\n");
			else
				rev_rotate(b, "rrb\n");
		}
		push(b, a, "pa\n");
		rotate(a, "ra\n");
	}
}
