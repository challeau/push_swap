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

/* stack a has the items to sort, stack b is a work stack. */
int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		stack_size;

	if (ac < 2 || *av[1] == '\0')
		error(NULL);
	a = get_stack(av + 1);
	b = NULL;
	stack_size = stack_len(a);
	if (stack_is_sorted(a) == false)
	{
		if (stack_size <= 5)
			sort_small_stack(&a, &b, stack_size);
		else
			sort_big_stack(&a, &b);
	}
//	print_stacks(a, b);
	if (stack_is_sorted(a) == false)
		ft_putstr_fd("u ain't doing it right\n", 2);
	ft_memdel_stack(a);
	ft_memdel_stack(b);
	return (0);
}
