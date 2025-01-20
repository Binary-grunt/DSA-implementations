/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:52:37 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/20 08:59:06 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
int ft_iterative_factorial(int nb)
{
	int i;
	int count;

	if (nb < 0)
		return (0);
	i = 1;
	count = 1;
	while (i <= nb)
	{
		count *= i;
		i++;
	}
	return (count);
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	printf("%d", ft_iterative_factorial(atoi(argv[1])));
// }
