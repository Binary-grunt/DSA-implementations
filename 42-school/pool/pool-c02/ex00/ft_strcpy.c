/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:11:58 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/11 22:24:13 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	*src;
// 	char	dest[10];
// 	char	*rest;
//
// 	src = "croissant";
// 	printf("src= %s\n", src);
// 	rest = ft_strcpy(dest, src);
// 	printf("src= %s, dest= %s, rest= %s\n", src, dest, rest);
// }
