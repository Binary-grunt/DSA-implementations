/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 06:29:36 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/17 07:09:38 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int ft_strlen(char *str)
{
	if (*str == '\0')
	{
		return (0);
	}
	return (ft_strlen(str + sizeof(char)) + 1);
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	printf("%d", ft_strlen(argv[1]));
// }
