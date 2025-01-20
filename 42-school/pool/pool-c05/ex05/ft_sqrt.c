/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:50:16 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/10/01 13:32:21 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

int ft_sqrt(int nb)
{
	int i;

	if (nb < 1)
	{
		return (0);
	}
	i = 1;
	while ((i * i) < nb)
	{
		i++;
	}
	if ((i * i) == nb)
	{
		return (i);
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	printf("%d", ft_sqrt(atoi(argv[1])));
// }
