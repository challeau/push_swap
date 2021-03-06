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

/*
** Pushes the first node of stack b to stack a, according to the index
** if the index is less than 3.
*/
static void	insert_first_half(t_node **a, t_node **b, int index)
{
	if (index == 0)
		push(b, a, e_STACK_A);
	else if (index == 1)
	{
		push(b, a, e_STACK_A);
		swap(a, e_STACK_A);
	}
	else if (index == 2)
	{
		rotate(a, e_STACK_A);
		push(b, a, e_STACK_A);
		swap(a, e_STACK_A);
		rev_rotate(a, e_STACK_A);
	}
}

/*
** Pushes the first node of stack b to stack a, according to the index
** if the index is greater than 2.
*/
static void	insert_second_half(t_node **a, t_node **b, int index)
{
	if (index == 3 && stack_len(*a) != 3)
	{
		rev_rotate(a, e_STACK_A);
		push(b, a, e_STACK_A);
		rotate(a, e_STACK_A);
		rotate(a, e_STACK_A);
	}
	else if (index == stack_len(*a))
	{
		push(b, a, e_STACK_A);
		rotate(a, e_STACK_A);
	}
}

/*
** Sorts stakcs of size 4 and 5.
*/
static void	sort_4_5(t_node **a, t_node **b, int stack_size)
{
	int	i;
	int	index;

	i = 0;
	while (i < stack_size / 2)
	{
		push(a, b, e_STACK_B);
		i++;
	}
	if (stack_is_sorted(*a) == false)
		sort_small_stack(a, b, stack_len(*a));
	while (stack_len(*a) < stack_size)
	{
		index = get_node_insertion_id(*a, (*b)->data);
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
		swap(a, e_STACK_A);
	else if (stack_size == 3)
	{
		last = (*a)->next->next->data;
		if (first < last || (first > second && second > last))
		{
			swap(a, e_STACK_A);
			first = (*a)->data;
			second = (*a)->next->data;
		}
		if (first > second)
			rotate(a, e_STACK_A);
		if (second > last)
			rev_rotate(a, e_STACK_A);
	}
	else
		sort_4_5(a, b, stack_size);
}
