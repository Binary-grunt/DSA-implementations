/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:10:18 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/10/01 15:36:31 by codegrunt	      ###   ########.fr       */
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

int main(int argc, char **argv)
{
	(void) argc;
	ft_putstr(argv[0]);
	write(1, "\n", 1);
}
