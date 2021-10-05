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

void	sort_big_stack(t_node **a, t_node **b)
{
	int	min;

	min = INT_MIN;
	while (*a)
	{
		min = get_next_min(*a, min);
		while ((*a)->data != min)
		{
			if (node_id(*a, min) < stack_len(*a) / 2)
				rotate(a, "ra\n");
			else
				rev_rotate(a, "rra\n");	
		}
		push(a, b, "pb\n");
	}
	while (*b)
		push(b, a, "pa\n");
}
