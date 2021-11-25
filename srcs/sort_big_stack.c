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

void	partition(t_node **a, t_node **b, int pivot)
{
	char	*ins = ft_strdup("");
	t_node *ptr = (*a);

	while (ptr != NULL && stack_max(ptr) > pivot)
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
			push(a, b, e_STACK_B);
		else if (ins[i] == 'r')
			rotate(a, e_STACK_A);
	}
	ft_memdel(ins);
}

void	apply_op(t_node **head, enum e_stack_id stack_id, int rep,
		 void (*operation)(t_node **, enum e_stack_id))
{
	while (rep > 0)
	{
		operation(head, stack_id);
		rep--;
	}
}

void	move_node(t_node **src, t_node **dst, int node_data, enum e_stack_id src_id)
{
	int			node_id;
	int			node_insertion_id;
	enum e_stack_id	dst_id;

	if (src_id == e_STACK_A)
		dst_id = e_STACK_B;
	else
		dst_id = e_STACK_A;
	node_id = get_node_id(*src, node_data);
	node_insertion_id = get_node_insertion_id(*dst, node_data);
	if (node_id <= stack_len(*src) / 2)
		apply_op(src, src_id, node_id, rotate);
	else
		apply_op(src, src_id, stack_len(*src) - node_id, rev_rotate);
	if (node_insertion_id == stack_len(*dst))
	{
		push(src, dst, dst_id);
		rotate(dst, dst_id);
	}
	else
	{
		if (node_insertion_id <= stack_len(*dst) / 2)
			apply_op(dst, dst_id, node_insertion_id, rotate);
		else
			apply_op(dst, dst_id,
				 stack_len(*dst) - node_insertion_id, rev_rotate);
		push(src, dst, dst_id);
	}
}

int	get_next_node(t_node *head)
{
	int	min;
	int	max;
	int	num_ops_min;
	int	num_ops_max;

	min = stack_min(head);
	max = stack_max(head);
	if (get_node_id(head, min) < stack_len(head) / 2)
		num_ops_min = get_node_id(head, min);
	else
		num_ops_min = stack_len(head) - get_node_id(head, min);
	if (get_node_id(head, max) < stack_len(head) / 2)
		num_ops_max = get_node_id(head, max);
	else
		num_ops_max = stack_len(head) - get_node_id(head, max);
	if (num_ops_min < num_ops_max)
		return (min);
	return (max);
}

void	sort_big_stack(t_node **a, t_node **b)
{
	long	med_data;
	int	min, max, next;
	
	min = stack_min(*a);
	max = stack_max(*a);
	move_node(a, b, min, e_STACK_A);
	move_node(a, b, max, e_STACK_A);
	while (stack_len(*a) > 5)
	{
		med_data = unbiased_stack_avg(a);
		partition(a, b, med_data);
	}
	if (stack_is_sorted(*a) == false)
		sort_small_stack(a, b, stack_len(*a));
	move_node(b, a, stack_max(*b), e_STACK_B);
	move_node(b, a, stack_min(*b), e_STACK_B);
	while (*b)
	{
		next = get_next_node(*b);
		while ((*b)->data != next)
		{
			if (get_node_id(*b, next) <= stack_len(*b) / 2)
				rotate(b, e_STACK_B);
			else
				rev_rotate(b, e_STACK_B);
		}
		move_node(b, a, (*b)->data, e_STACK_B);
	}
	stack_pointer_to_min(a);
}
