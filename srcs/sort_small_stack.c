/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:17:02 by challeau          #+#    #+#             */
/*   Updated: 2021/09/20 17:17:02 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	insert_first_half(t_node **a, t_node **b, int index)
{
	if (index == 0)
		push(a, b, e_INS_A);
	else if (index == 1)
	{
		push(a, b, e_INS_A);
		swap(a, b, e_INS_A);
	}
	else if (index == 2)
	{
		rotate(a, b, e_INS_A);
		push(a, b, e_INS_A);
		swap(a, b, e_INS_A);
		rev_rotate(a, b, e_INS_A);
	}
}

static void	insert_second_half(t_node **a, t_node **b, int index)
{
	if (index == 3 && stack_len(*a) != 3)
	{
		rev_rotate(a, b, e_INS_A);
		push(a, b, e_INS_A);
		rotate(a, b, e_INS_A);
		rotate(a, b, e_INS_A);
	}
	else if (index == stack_len(*a))
	{
		push(a, b, e_INS_A);
		rotate(a, b, e_INS_A);
	}
}

/*
** Sorts stakcs of size 4 and 5.
*/
static void	sort_4_5(t_node **a, t_node **b)
{
	int	index;

	while (stack_len(*a) > 3)
		push(a, b, e_INS_B);
	if (stack_is_sorted(*a) == false)
		sort_small_stack(a, b, 3);
	while ((*b) != NULL)
	{
		index = node_index(*a, (*b)->data);
		if (index <= 2)
			insert_first_half(a, b, index);
		else
			insert_second_half(a, b, index);
	}
}

/*
** Sorts stack of size 2 to 5.
*/
void	sort_small_stack(t_node **a, t_node **b, int stack_size)
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
		sort_4_5(a, b);
}
