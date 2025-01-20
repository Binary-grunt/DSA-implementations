/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:36:19 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/16 09:56:21 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int ft_strlen(char *str)
{
	if (*str == '\0')
		return (1);
	return (ft_strlen(str + sizeof(char)) + 1);
}

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int dest_len;
	int src_len;
	int i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (i < (src_len - 1) && (unsigned int) i < nb)
	{
		dest[i + dest_len - 1] = src[i];
		i++;
	}
	dest[i + dest_len - 1] = '\0';
	return (dest);
}
