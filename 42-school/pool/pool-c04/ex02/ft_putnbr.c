/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:42:17 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/18 13:59:18 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	int n;
	n = -2147483648;

	if (nb == n)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
		return;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
		return;
	}
	ft_putchar(nb + '0');
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	ft_putnbr(atoi(argv[1]));
// }
