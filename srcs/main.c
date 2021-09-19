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

/*
** Sorts stack of size 2 or 3.
*/
static void	smol_sort(t_node **a, t_node **b, int stack_size)
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
	print_stack(a);
	ft_memdel_stack(a);
	ft_memdel_stack(b);
	return (0);
}
