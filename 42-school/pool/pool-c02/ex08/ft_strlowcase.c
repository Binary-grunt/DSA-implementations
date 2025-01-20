/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:16:27 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/12 09:37:32 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char *ft_strlowcase(char *str)
{
	int        i;
	const char offset = 'a' - 'A';

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += offset;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char	entry[] = "CROISSANT AUX AMANDES!";
// 	printf("croissant= %s\n", ft_strlowcase(entry));
// }
