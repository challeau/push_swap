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

/* static int	get_significant_digit(int num, int exp) */
/* { */
/* 	return (num / exp % 10); */
/* } */

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

/* static t_node *rev_lst(t_node *head) */
/* { */
/* 	t_node	*new; */
/* 	t_node	*ptr; */

/* 	new = NULL; */
/* 	ptr = head; */
/* 	while (ptr != NULL) */
/* 	{ */
/* 		add_node_front(&new, ptr->data); */
/* 		ptr = ptr->next; */
/* 	} */
/* 	return (new); */
/* } */

/* void	apply_op(t_node **a, int op_num, char *str) */
/* { */
/* 	int op; */
/* 	void (*ops[2])(t_node **head, char *str); */

/* 	op = 0; */
/* 	ops[0] = rotate; */
/* 	ops[1] = rev_rotate; */
/* 	if (ft_strcmp(str, "ra\n") != 0 && ft_strcmp(str, "rb\n") != 0) */
/* 		op = 1; */
/* 	while (op_num) */
/* 	{ */
/* 		ops[op](a, str); */
/* 		op_num--; */
/* 	} */
/* } */

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

void	move_node(t_node **from, t_node **to, int node_data)
{
	int	node_id;
	int	node_insertion_id;

	node_id = get_node_id(*from, node_data);
	node_insertion_id = get_node_insertion_id(*to, node_data);
//	printf("data:%d, id a:%d, id b:%d\n", node_data, node_id, node_insertion_id);
//	print_stacks(*from, *to);
	while ((*from)->data != node_data)
	{
		if (node_id <= stack_len(*from) / 2)
			rotate(from, "ra\n");		// WRONG TEXT
		else
			rev_rotate(from, "rra\n");
	}
//	print_stacks(*from, *to);
//	printf("stack_len: %d   vs   ins_id: %d\n", stack_len(*to), node_insertion_id);
	if (node_insertion_id == stack_len(*to))
	{
		push(from, to, "pb\n");
		rotate(to, "rb\n");
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
				rotate(to, "ra\n");		// WRONG TEXT
			else
				rev_rotate(to, "rra\n");
			rot_num--;
		}
		push(from, to, "pb\n");
	}
//	print_stacks(*from, *to);
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

long	unbiased_avg(t_node **a)
{
	float dev, mean, var, sumsqr = 0, std_dev;
	t_node *ptr = *a;
	t_node *unbiased_stack = NULL;

	mean = avg(*a);
	while (ptr)
	{
		dev = ptr->data - mean;
		sumsqr += dev * dev;
		ptr = ptr->next;
	}
	var = sumsqr / stack_len(*a);
	std_dev = sqrt(var);
	ptr = *a;
	while (ptr)
	{
		if (ptr->data < std_dev && ptr->data > std_dev * -1)
			add_node_back(&unbiased_stack, ptr->data);
		ptr = ptr->next;
	}
	if (unbiased_stack == NULL || std_dev / mean < 1)
		return (mean);
	long res = avg(unbiased_stack);
	ft_memdel_stack(unbiased_stack);
	return (res);
}

void	sort_big_stack(t_node **a, t_node **b)
{
	long	med_data;
	int	min, max, next;
	
	min = get_min(*a);
	max = get_max(*a);
	move_node(a, b, min);
	move_node(a, b, max);
	while (stack_len(*a) > 5)
	{
		med_data = unbiased_avg(a);
//		printf("%ld -> max=%d, min=%d\n", med_data, get_max(*a), get_min(*a));
		partition(a, b, med_data);
	}
	if (stack_is_sorted(*a) == false)
		sort_small_stack(a, b, stack_len(*a));
//	print_stacks(*a, *b);
	move_node(b, a, get_max(*b));
	move_node(b, a, get_min(*b));
//	print_stacks(*a, *b);
	while (*b)
	{
//		print_stacks(*a, *b);
		next = get_next_node(*b);
		while ((*b)->data != next)
		{
			if (get_node_id(*b, next) <= stack_len(*b) / 2)
				rotate(b, "rb\n");
			else
				rev_rotate(b, "rrb\n");
		}
		move_node(b, a, (*b)->data);
	}
	stack_pointer_to_min(a);
}

