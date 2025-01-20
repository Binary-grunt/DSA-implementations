/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:12:17 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/12 08:22:11 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	printf("%d\n", ft_str_is_uppercase("CROISSANT"));
// 	printf("%d\n", ft_str_is_uppercase("CroissanT"));
// 	printf("%d\n", ft_str_is_uppercase("4"));
// }
