/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:33:02 by challeau          #+#    #+#             */
/*   Updated: 2021/11/25 16:33:02 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int num)
{
	int	start;
	int	mid;
	int	end;

	start = 1;
	end = INT_MAX;
	if (num == 0 || num == 1)
		return (num);
	while (start < end - 1)
	{
		mid = start + (end - start) / 2;
		if (mid == num / mid)
			return (mid);
		else if (mid > num / mid)
			end = mid;
		else
			start = mid;
	}
	return (start);
}
