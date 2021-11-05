/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:52:07 by challeau          #+#    #+#             */
/*   Updated: 2021/09/16 11:52:07 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Parses the stack and checks that arg is not already stored.
** Returns true if it finds a duplicate.
*/
static bool	check_for_duplicates(t_node *head, int arg)
{
	t_node	*ptr;

	if (head == NULL)
		return (false);
	ptr = head;
	while (ptr->next != NULL)
	{
		if (ptr->data == arg)
			return (true);
		ptr = ptr->next;
	}
	if (ptr->data == arg)
		return (true);
	return (false);
}

/*
** Performs validity checks and, if all pass, adds a node to the stack passed
** in argument. Returns true upon success.
*/
static bool	check_and_add_arg(t_node **head, char *arg)
{
	if (ft_str_isnum(arg) == false)
		return (false);
	if (ft_strlen(arg) > 11)
		return (false);
	if (ft_strlen(arg) >= 10)
	{
		if (*arg == '-' && ft_strlen(arg) == 11 &&
		    ft_strcmp("-2147483648", arg) < 0)
			return (false);
		else if (ft_strcmp("2147483647", arg) < 0)
			return (false);
	}
	if (check_for_duplicates(*head, ft_atoi(arg)) == true)
		return (false);
	if (add_node_back(head, ft_atoi(arg)) == false)
		return (false);
	return (true);
}

/*
** Parses the arguments and returns a stack containing the items to sort.
** If the argument is not formated correctly, or if there are duplicated,
** the error function is called.
*/
t_node	*get_stack(char **args)
{
	uint			i;
	char			**tmp_data;
	char			**stack_data;
	static t_node	*new_stack = NULL;

	i = 0;
	tmp_data = NULL;
	stack_data = args;
	if (i == 0 && ft_char_rep_count(' ', args[i]) > 0)
	{
		tmp_data = ft_split(args[i], ' ');
		stack_data = tmp_data;
	}
	while (stack_data[i] != NULL)
	{
		if (check_and_add_arg(&new_stack, stack_data[i]) == false)
		{
			if (tmp_data != NULL)
				ft_memdel_strptr(tmp_data);
			error(new_stack);
		}
		i++;
	}
	if (tmp_data != NULL)
		ft_memdel_strptr(tmp_data);
	return (new_stack);
}
