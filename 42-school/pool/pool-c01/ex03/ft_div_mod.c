/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:44:27 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/11 19:58:23 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
	int res_div;
	int res_mod;

	res_div = a / b;
	res_mod = a % b;
	*div = res_div;
	*mod = res_mod;
}

// int	main(void)
// {
// 	int	a;
// 	int	b;
// 	int	div;
// 	int	mod;
//
// 	a = 42;
// 	b = 24;
// 	div = 0;
// 	mod = 0;
//
// 	ft_div_mod (a, b, &div, &mod);
//
// 	printf("a: %d, b: %d, div: %d, mod: %d\n", a, b, div, mod);
// }
