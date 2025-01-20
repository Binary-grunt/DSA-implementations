/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:40:18 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/10/01 14:02:31 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

int ft_is_prime(int nb)
{
	int i;
	i = 2;

	if (nb <= 1)
	{
		return (0);
	}
	while (i < nb)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	printf("%d", ft_is_prime(atoi(argv[1])));
// }
