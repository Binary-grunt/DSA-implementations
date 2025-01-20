/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:19:21 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/18 14:59:22 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int ft_atoi(char *str)
{
	int count;
	int mult;

	count = 0;
	mult = 1;
	while ((*str >= 8 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			mult = -mult;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		count = (count * 10) + (*str - '0');
		str++;
	}
	return (mult * count);
}
