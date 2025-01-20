/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:14:12 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/10/03 09:56:11 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
	if (*str == '\0')
	{
		return;
	}
	write(1, str, 1);
	ft_putstr(str + sizeof(char));
}

void rec_rev_params(int argc, char **argv)
{
	if (argc == 0)
	{
		return;
	}
	if (argc > 1)
	{
		rec_rev_params(argc - 1, argv + 1);
	}
	ft_putstr(*argv);
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	rec_rev_params(argc - 1, argv + 1);
}
