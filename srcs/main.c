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

	if (ac < 2 || *av[1] == '\0')
		error(NULL);
	a = get_stack(av + 1);
	b = NULL;
	print_stack(a);
	print_stack(b);
	rev_rotate(&a, &b, e_INS_A);
	print_stack(a);
	print_stack(b);
	push(&a, &b, e_INS_B);
	push(&a, &b, e_INS_B);
	push(&a, &b, e_INS_B);
	rotate(&a, &b, e_INS_AB);
	print_stack(a);
	print_stack(b);
	ft_memdel_stack(a);
	ft_memdel_stack(b);
	return (0);
}
