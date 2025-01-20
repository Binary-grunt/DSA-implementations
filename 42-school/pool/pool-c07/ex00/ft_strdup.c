/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:24:12 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/10/03 10:56:11 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (1 + ft_strlen(str + sizeof(char)));
}

char *ft_strdup(char *src)
{
	int   i;
	char *dest;

	i = 0;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == 0)
	{
		return (0);
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
