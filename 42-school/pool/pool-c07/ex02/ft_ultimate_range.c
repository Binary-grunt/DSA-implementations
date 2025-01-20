/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:24:32 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/10/03 14:52:21 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
	int  n;
	int *tab;
	int  size;

	size = max - min;
	tab = malloc(sizeof(*tab) * (size));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (tab == NULL)
	{
		*range = NULL;
		return (-1);
	}
	n = 0;
	while (min < max)
	{
		tab[n] = min;
		n++;
		min++;
	}
	*range = tab;
	return (size);
}
