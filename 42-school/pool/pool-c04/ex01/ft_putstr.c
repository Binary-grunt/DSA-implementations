/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:25:55 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/18 12:48:56 by codegrunt	      ###   ########.fr       */
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

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	ft_putstr(argv[1]);
// }
