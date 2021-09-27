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

static void	find_data_limits(t_node *head, int *min, int *max)
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

int	get_index(t_node *head, int to_add)
{
	t_node *ptr = head;
	int index = 0;
	
	while (ptr != NULL)
	{
		if (ptr->data > to_add)
			return (index);
		index++;
		ptr = ptr->next;
	}
	return (index);
}

/*
** Sorts stack of 6+.
*/
void	sort_big_stack(t_node **a, t_node **b)
{
	int	min_data, max_data, med_data;
	
	while (stack_len(*a) > 5)
	{
		find_data_limits(*a, &min_data, &max_data);
		med_data = (min_data + max_data) / 2;
		partition(a, b, med_data);
	}
	if (stack_is_sorted(*a) == false)
		sort_small_stack(a, b, stack_len(*a));
	while (*b != NULL)
	{
		find_data_limits(*a, &min_data, &max_data);
		if ((*b)->data < max_data)
		{
			int i = stack_len(*a) - get_index(*a, (*b)->data);
			while (i > 0)
			{
			     rev_rotate(a, "rra\n");
			     i--;
			}
			push(b, a, "pa\n");
			while (min_data < (*a)->data)
				rotate(a, "ra\n");
		}
		else
		{
			push(b, a, "pa\n");
			rotate(a, "ra\n");
		}
	}
}
