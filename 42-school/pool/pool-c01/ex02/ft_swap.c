/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:32:46 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/11 19:41:43 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void ft_swap(int *a, int *b)
{
	int val_a;
	int val_b;

	val_a = *a;
	val_b = *b;
	*a = val_b;
	*b = val_a;
}

// int	main(void)
// {
// 	int a;
// 	int b;
//
// 	a = 42;
// 	b = 24;
// 	printf("a- %d, b- %d\n", a, b);
//
// 	ft_swap (&a, &b);
// 	printf("a- %d, b- %d", a, b);
// }
