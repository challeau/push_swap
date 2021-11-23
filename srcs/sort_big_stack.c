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

long	avg(t_node *a)
{
	t_node *ptr;
	long sum;

	sum = 0;
	ptr = a;
	while (ptr != NULL)
	{
		sum += ptr->data;
		ptr = ptr->next;
	}
	return (sum / stack_len(a));
}

static int	get_max(t_node *head)
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

static int	get_min(t_node *head)
{
	int	min;
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

void	partition(t_node **a, t_node **b, int pivot)
{
	char	*ins = ft_strdup("");
	t_node *ptr = (*a);

	while (ptr != NULL && get_max(ptr) > pivot)
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

void	move_node(t_node **from, t_node **to, int node_data, enum e_stack_id from_ID)
{
	int	node_id;
	int	node_insertion_id;
	char	*ins[6];

	node_id = get_node_id(*from, node_data);
	node_insertion_id = get_node_insertion_id(*to, node_data);
	ins[0] = "ra\n";
	ins[1] = "rb\n";
	ins[2] = "rra\n";
	ins[3] = "rrb\n";
	ins[4] = "pb\n";
	ins[5] = "pa\n";
	while ((*from)->data != node_data)
	{
		if (node_id <= stack_len(*from) / 2)
			rotate(from, ins[from_ID]);
		else
			rev_rotate(from, ins[2 + from_ID]);
	}
	if (node_insertion_id == stack_len(*to))
	{
		push(from, to, ins[4 + from_ID]);
		rotate(to, ins[1 - from_ID]);
	}
	else
	{
		int rot_num = 0;
		if (node_insertion_id <= stack_len(*to) / 2)
			rot_num = node_insertion_id;
		else
			rot_num = stack_len(*to) - node_insertion_id;
		while (rot_num > 0)
		{
			if (node_insertion_id <= stack_len(*to) / 2)
				rotate(to, ins[1 - from_ID]);
			else
				rev_rotate(to, ins[3 - from_ID]);
			rot_num--;
		}
		push(from, to, ins[4 + from_ID]);
	}
}

int	get_next_node(t_node *head)
{
	int	min = get_min(head);
	int	max = get_max(head);

	int num_ops_min;
	int num_ops_max;

	num_ops_min = get_node_id(head, min) < stack_len(head) / 2 ? get_node_id(head, min) : stack_len(head) - get_node_id(head, min);
	num_ops_max = get_node_id(head, max) < stack_len(head) / 2 ? get_node_id(head, max) : stack_len(head) - get_node_id(head, max);
	if (num_ops_min < num_ops_max)
		return (min);
	return (max);
}

void	stack_pointer_to_min(t_node **a)
{
	int	min = get_min(*a);

	if (get_node_id(*a, min) < stack_len(*a) / 2)
	{
		while ((*a)->data != min)
			rotate(a, "ra\n");
	}
	else
	{
		while ((*a)->data != min)
			rev_rotate(a, "rra\n");
	}
}

int	ft_sqrt(int x)
{
	if(x == 0 || x == 1){
		return x;
	}

	int start = 1, end = 2147483647;

	while (start + 1 < end){
		int mid = start + (end - start) / 2;
		if(mid == x/mid){
			return mid;
		} else if(mid > x/mid){
			end = mid;
		} else{
			start = mid;
		}
	}      
	return start;
}

float	get_standard_dev(t_node *head)
{
	float	dev;
	float	var;
	float	sumsqr;
	t_node	*ptr = head;

	sumsqr = 0;
	while (ptr)
	{
		dev = ptr->data - avg(head);
		sumsqr += dev * dev;
		ptr = ptr->next;
	}
	var = sumsqr / stack_len(head);
	return (ft_sqrt(var));
}

int	unbiased_avg(t_node **a)
{
	int	unbiased_avg;
	float	std_dev;
	t_node *ptr;
	t_node *unbiased_stack = NULL;

	std_dev = get_standard_dev(*a);
	ptr = *a;
	while (ptr)
	{
		if (ptr->data < std_dev && ptr->data > std_dev * -1)
			add_node_back(&unbiased_stack, ptr->data);
		ptr = ptr->next;
	}
	if (unbiased_stack == NULL || std_dev / avg(*a) < 1)
		return (avg(*a));
	unbiased_avg = avg(unbiased_stack);
	ft_memdel_stack(unbiased_stack);
	return (unbiased_avg);
}

void	sort_big_stack(t_node **a, t_node **b)
{
	long	med_data;
	int	min, max, next;
	
	min = get_min(*a);
	max = get_max(*a);
	move_node(a, b, min, e_STACK_A);
	move_node(a, b, max, e_STACK_A);
	while (stack_len(*a) > 5)
	{
		med_data = unbiased_avg(a);
		partition(a, b, med_data);
	}
	if (stack_is_sorted(*a) == false)
		sort_small_stack(a, b, stack_len(*a));
	move_node(b, a, get_max(*b), e_STACK_B);
	move_node(b, a, get_min(*b), e_STACK_B);
	while (*b)
	{
		next = get_next_node(*b);
		while ((*b)->data != next)
		{
			if (get_node_id(*b, next) <= stack_len(*b) / 2)
				rotate(b, "rb\n");
			else
				rev_rotate(b, "rrb\n");
		}
		move_node(b, a, (*b)->data, e_STACK_B);
	}
	stack_pointer_to_min(a);
}

