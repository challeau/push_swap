/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strptrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:30:47 by challeau          #+#    #+#             */
/*   Updated: 2021/02/06 13:30:47 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strptrdup(char **src)
{
	size_t	len;
	char	**new;

	len = 0;
	while (src[len])
		len++;
	new = (char **)malloc((len + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	len = 0;
	while (src[len])
	{
		new[len] = ft_strdup(src[len]);
		len++;
	}
	new[len] = NULL;
	return (new);
}
