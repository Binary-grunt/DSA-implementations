/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:34:10 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/09/11 20:41:22 by codegrunt        ###   ########.fr       */
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

// int	main(void)
// {
// 	ft_putstr ("Hello worldy world");
// }
