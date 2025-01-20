/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:46:37 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/12 10:17:22 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int is_alpha_num(char str)
{
	if ((str >= '0' && str <= '9') || (str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z'))
		return (1);
	return (0);
}

int ft_str_uppercase(char str)
{
	const char offset = 'a' - 'A';

	if (str >= 'a' && str <= 'z')
		return (str - offset);
	return (str);
}

int ft_str_lowercase(char str)
{
	const char offset = 'a' - 'A';

	if (str >= 'A' && str <= 'Z')
		return (str + offset);
	return (str);
}

char *ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_str_lowercase(str[i]);
		i++;
	}
	i = 0;
	if (is_alpha_num(str[0]))
		str[i] = ft_str_uppercase(str[i]);
	while (str[i] != '\0')
	{
		if (is_alpha_num(str[i]) && !is_alpha_num(str[i - 1]))
			str[i] = ft_str_uppercase(str[i]);
		i++;
	}
	return (str);
}
