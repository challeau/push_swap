/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:54:29 by challeau          #+#    #+#             */
/*   Updated: 2021/09/16 11:54:29 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Frees the stack, outputs an error message and exits.
*/
void	error(t_node *head)
{
	if (head)
		ft_memdel_stack(head);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
