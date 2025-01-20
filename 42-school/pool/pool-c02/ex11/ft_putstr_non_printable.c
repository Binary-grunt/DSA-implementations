/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:56:37 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/14 11:47:12 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr_non_printable(char *str)
{
	if (*str == '\0')
		return;
	if (*str < ' ' || *str > '~')
	{
		ft_putchar('\\');
		ft_putchar("0123456789abcdef"[*str / 16]);
		ft_putchar("0123456789abcdef"[*str % 16]);
	}
	else
		ft_putchar(*str);
	ft_putstr_non_printable(str + sizeof(char));
}
