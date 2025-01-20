/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:10:10 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/11 20:17:23 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
{
	int x;
	int y;

	x = *a / *b;
	y = *a % *b;
	*a = x;
	*b = y;
}

// int	main(void)
// {
// 	int	a;
// 	int	b;
//
// 	a = 42;
// 	b = 24;
// 	printf ("a = %d, b = %d\n", a, b);
// 	ft_ultimate_div_mod (&a, &b);
// 	printf ("a: %d, b: %d\n", a, b);
// }
