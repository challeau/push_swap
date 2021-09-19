#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/types.h>
#include "libft/libft.h"

#include <stdio.h>
#include <assert.h>

typedef struct	s_node{
	int			data;
	struct s_node	*next;
}		t_node;

enum		e_ins_info {
	e_INS_A,
	e_INS_B,
	e_INS_AB,
};

/* NODES */
bool	add_node_after(t_node **prev_node, int data);
bool	add_node_back(t_node **head, int data);
bool	add_node_front(t_node **head, int data);
int	pop(t_node **head);

/* STACKS */
void	ft_memdel_stack(t_node *head);
int	peek(t_node *head);
void	print_stack(t_node *node);
bool	stack_is_sorted(t_node *head);
int	stack_len(t_node *head);

/* INSTRUCTIONS */
void	push(t_node **a, t_node **b, enum e_ins_info ins_info);
void	rev_rotate(t_node **a, t_node **b, enum e_ins_info ins_info);
void	rotate(t_node **a, t_node **b, enum e_ins_info ins_info);
void	swap(t_node **a, t_node **b, enum e_ins_info ins_info);

/* PARSER */
t_node	*get_stack(char **args);

/* UTILS */
void	error(t_node *head);
int	find_num_spot(t_node *head, int num);

#endif