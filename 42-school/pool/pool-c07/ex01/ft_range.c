/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:14:12 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/10/03 12:46:11 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int min, int max)
{
	int *dest;
	int  size;
	int  i;

	size = max - min;
	if (min >= max)
	{
		return (0);
	}
	dest = malloc(sizeof(int) * size);
	if (dest == 0)
	{
		return (0);
	}
	i = 0;
	while (i < size)
	{
		dest[i] = min;
		min++;
		i++;
	}
	return (dest);
}
