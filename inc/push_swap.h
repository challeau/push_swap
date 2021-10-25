#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/types.h>
#include "libft/libft.h"

#include <stdio.h>
#include <assert.h>

typedef struct s_node{
	int			data;
	int			index;
	struct s_node	*next;
}		t_node;

/* SORTING */
void	sort_small_stack(t_node **a, t_node **b, int stack_size);
void	sort_big_stack(t_node **a, t_node **b);
void	partition(t_node **a, t_node **b, int pivot);

/* NODES */
bool	add_node_after(t_node **prev_node, int data);
bool	add_node_back(t_node **head, int data);
bool	add_node_front(t_node **head, int data);
int	pop(t_node **head);
int	node_index(t_node *head, int node_data);

/* STACKS */
void	ft_memdel_stack(t_node *head);
int	peek(t_node *head);
void	print_stacks(t_node *a, t_node *b);
bool	stack_is_sorted(t_node *head);
bool	stack_is_revsorted(t_node *head);
int	stack_len(t_node *head);

/* INSTRUCTIONS */
void	push(t_node **src, t_node **dest, char *str);
void	rev_rotate(t_node **head, char *str);
void	rotate(t_node **head, char *str);
void	swap(t_node **head, char *str);

/* PARSER */
t_node	*get_stack(char **args);

/* UTILS */
void	error(t_node *head);
void	find_data_limits(t_node *head, long *min, long *max);
int	get_next_min(t_node *head, int prev_min);
int	node_id(t_node *head, int node_data);

#endif