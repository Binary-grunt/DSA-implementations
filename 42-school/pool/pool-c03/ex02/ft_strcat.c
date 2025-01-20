/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:29:12 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/16 13:13:31 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int ft_strlen(char *str)
{
	if (*str == '\0')
		return (1);
	return (ft_strlen(str + sizeof(char)) + 1);
}

char *ft_strcat(char *dest, char *src)
{
	int dest_len;
	int src_len;
	int i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (i < (src_len - 1))
	{
		dest[i + dest_len - 1] = src[i];
		i++;
	}
	dest[i + dest_len - 1] = '\0';
	return (dest);
}
