#include "../inc/push_swap.h"

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

static bool	check_and_add_arg(t_node **head, char *arg)
{
	if (ft_str_isnum(arg) == false)
		return (false);
	if (ft_strlen(arg) >= 9)
	{
		if (*arg == '-' && ft_strcmp("-2147483648", arg) < 0)
			return (false);
		else if (ft_strcmp("2147483647", arg) < 0)
			return (false);
	}
	if (check_for_duplicates(*head, ft_atoi(arg)) == true)
		return (false);
	if (add_node_back(head, ft_atoi(arg)) == false)
		return (false);
	return  (true);
}

static uint8_t	stack_len(t_node *head)
{
	uint8_t	len;
	t_node	*ptr;

	len = 0;
	ptr = head;
	while(ptr->next != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	len++;
	return (len);
}

t_node	*get_stack(char **args)
{
	uint8_t		i;
	char		**tmp_data;
	static t_node	*new_stack = NULL;

	i = 0;
	tmp_data = NULL;
	while (args[i] != NULL)
	{
		if (i == 0 && ft_char_rep_count(' ', args[i]) > 0)
		{
			tmp_data = ft_split(args[i], ' ');
			get_stack(tmp_data);
			ft_memdel_strptr(tmp_data);
			return (new_stack);
		}
		else if (i != 0 && ft_char_rep_count(' ', args[i]) > 0)
			error(new_stack, NULL);
		if (check_and_add_arg(&new_stack, args[i]) == false)
			error(new_stack, NULL);
		i++;
	}
	if (stack_len(new_stack) < 2)
		error(new_stack, NULL);
	return (new_stack);
}
