/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:02:07 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/12 09:12:02 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char *ft_strupcase(char *str)
{
	int        i;
	const char offset = 'a' - 'A';

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= offset;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char	entry[] = "Croissant aux Amandes!!";
// 	printf("croissant= %s\n", ft_strupcase(entry));
// }
