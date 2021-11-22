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

/* void	push_next_node(t_node **a, t_node **b, int exp) */
/* { */
/* 	t_node	*ptr; */
/* 	int dig, buff = 0; */

/* 	ptr = *b; */
/* 	dig = get_significant_digit((*a)->data, exp); */
/* 	/\* while ((dig > get_significant_digit((*a)->data, exp) || *\/ */
/* 	/\* 	(dig == get_significant_digit((*a)->data, exp) *\/ */
/* 	/\* 	 && get_significant_digit((*b)->data, exp / 10) > get_significant_digit((*a)->data, exp / 10))) *\/ */
/* 	/\*        && ptr != NULL) *\/ */
/* 	while (dig > get_significant_digit((*a)->data, exp) */
/* 	       && ptr != NULL)	 */
/* 	{ */
/* 		buff++; */
/* 		ptr = ptr->next; */
/* 	} */
/* 	if (buff < stack_len(*b) / 2) */
/* 	{ */
/* 		apply_op(b, buff, "ra\n"); */
/* 		push(a, b, "pb\n"); */
/* 		apply_op(b, buff, "rra\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		apply_op(b, stack_len(*b) - buff, "rra\n"); */
/* 		push(a, b, "pb\n"); */
/* 		apply_op(b, stack_len(*b) - buff, "ra\n"); */
/* 	} */
/* } */

/* void	count_sort(t_node **a, t_node **b, int exp) */
/* { */
/* 	int dig, buff = 0; */
/* 	push(a, b, "pb\n"); */
/* 	while (*a != NULL) */
/* 		push_next_node(a, b, exp); */
/* 	push(b, a, "pa\n"); */
/* 	while (*b != NULL) */
/* 	{ */
/* 		dig = get_significant_digit((*b)->data, exp); */
/* 		buff = 0; */
/* 		while ((dig > get_significant_digit((*a)->data, exp) || */
/* 		       (dig == get_significant_digit((*a)->data, exp) */
/* 			&& get_significant_digit((*b)->data, exp / 10) > get_significant_digit((*a)->data, exp / 10))) */
/* 		       && buff < stack_len(*a)) */
/* 		{ */
/* 			rotate(a, "ra\n"); */
/* 			buff++; */
/* 		} */
/* 		push(b, a, "pa\n"); */
/* 		while (buff > 0) */
/* 		{ */
/* 			rev_rotate(a, "rra\n"); */
/* 			buff--; */
/* 		} */
/* 	} */
	
/* } */

/* void	sort_big_stack(t_node **a, t_node **b) */
/* { */
/* 	int max = get_max(*a); */
/* 	int exp = 1; */
/* //	int turn = 1; */

/* 	while (max / exp > 9) */
/* 		exp *= 10; */
/* 	count_sort(a, b, exp); */
/* //	print_stacks(*a, *b); */
/* 	/\* while (exp && stack_is_sorted(*a) == false) *\/ */
/* 	/\* { *\/ */
/* 	/\* 	printf("%d\n", exp); *\/ */
/* 	/\* 	if (turn % 2 != 0) *\/ */
/* 	/\* 		count_sort(a, b, exp); *\/ */
/* 	/\* 	else *\/ */
/* 	/\* 		count_sort(b, a, exp); *\/ */
/* 	/\* 	exp /= 10;  *\/ */
/* 	/\* 	turn++; *\/ */
/* 	/\* } *\/ */
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

int	avg(t_node *a)
{
	t_node *ptr;
	int sum;

	sum = 0;
	ptr = a;
	while (ptr != NULL)
	{
		sum += ptr->data;
		ptr = ptr->next;
	}
	return (sum / stack_len(a));
}

//void	move_node()

void	sort_big_stack(t_node **a, t_node **b)
{
	long	med_data;
	int	min, max;

	min = get_min(*a);
	max = get_max(*a);
	/* move_node(a, b, min); */
	/* move_node(a, b, max); */
	while (stack_len(*a) > 5)
	{
		med_data = avg(*a);
//		printf("%ld -> max=%d, min=%d\n", med_data, get_max(*a), get_min(*a));
		partition(a, b, med_data);
	}
	if (stack_is_sorted(*a) == false)
		sort_small_stack(a, b, stack_len(*a));
//	print_stacks(*a, *b);
	while (*b)
	{
		/* if ((*b)->data > get_max(*a)) */
		/* { */
		/* 	push(b, a, "pa\n"); */
		/* 	rotate(a, "ra\n"); */
		/* } */
		/* if ((*b)->data < (*a)->data) */
		/* 	push(b, a, "pa\n"); */
		min = get_next_min(*b, min);
		while ((*b)->data != min)
		{
			if (node_id(*b, min) <= stack_len(*b) / 2)
				rotate(b, "rb\n");
			else
				rev_rotate(b, "rrb\n");
		}
		push(b, a, "pa\n");
		rotate(a, "ra\n");
	}
}

