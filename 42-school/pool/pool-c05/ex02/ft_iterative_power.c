/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:15:07 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/20 09:39:19 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// include <math.h>
int ft_iterative_power(int nb, int power)
{
	int i;
	int init;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	init = nb;
	while (i < power)
	{
		nb *= init;
		i++;
	}
	return (nb);
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	// printf("%d\n\n", pow(100, 0));
// 	printf("%d", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
// }
