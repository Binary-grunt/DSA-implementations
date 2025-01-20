/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:20:59 by codegrunt         #+#    #+#             */
/*   Updated: 2024/09/16 17:42:02 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char *ft_strstr(char *str, char *find)
{
	int i;
	int j;

	if (*find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find[0])
		{
			j = 0;
			while (str[i + j] == find[j] && find[j] != '\0')
			{
				j++;
			}
			if (find[j] == '\0')
			{
				return (str + (i * sizeof(char)));
			}
		}
		i++;
	}
	return (0);
}
