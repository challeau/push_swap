/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs/maths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:50:06 by challeau          #+#    #+#             */
/*   Updated: 2021/11/25 17:50:06 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Returns the average value of the stack.
*/
long	stack_avg(t_node *head)
{
	t_node	*ptr;
	long	sum;

	sum = 0;
	ptr = head;
	while (ptr != NULL)
	{
		sum += ptr->data;
		ptr = ptr->next;
	}
	return (sum / stack_len(head));
}

/*
** Returns the highest value of the stack.
*/
int	stack_max(t_node *head)
{
	int		max;
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

/*
** Returns the minimum value of the stack.
*/
int	stack_min(t_node *head)
{
	int		min;
	t_node	*ptr;

	min = INT_MAX;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data < min)
			min = ptr->data;
		ptr = ptr->next;
	}
	return (min);
}

/*
** Returns the standard deviation of the data in the stack.
*/
float	get_standard_dev(t_node *head)
{
	float	dev;
	float	var;
	float	sumsqr;
	t_node	*ptr;

	sumsqr = 0;
	ptr = head;
	while (ptr)
	{
		dev = ptr->data - stack_avg(head);
		sumsqr += dev * dev;
		ptr = ptr->next;
	}
	var = sumsqr / stack_len(head);
	return (ft_sqrt(var));
}

/*
** Calculates the average value of the stack, but without any outliers if the
** coefficient of variation (standard deviation/stack average) is > 1.
*/
int	unbiased_stack_avg(t_node **head)
{
	int		unbiased_avg;
	float	std_dev;
	t_node	*ptr;
	t_node	*unbiased_stack;

	std_dev = get_standard_dev(*head);
	ptr = *head;
	unbiased_stack = NULL;
	while (ptr)
	{
		if (ptr->data < std_dev && ptr->data > std_dev * -1)
			add_node_back(&unbiased_stack, ptr->data);
		ptr = ptr->next;
	}
	if (unbiased_stack != NULL)
		unbiased_avg = stack_avg(unbiased_stack);
	ft_memdel_stack(unbiased_stack);
	if (unbiased_stack == NULL || std_dev / stack_avg(*head) < 1)
		return (stack_avg(*head));
	return (unbiased_avg);
}
