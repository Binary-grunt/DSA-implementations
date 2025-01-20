/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:23:20 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/10/03 13:27:03 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c) { write(1, &c, 1); }

void ft_print_alphabet(void) {
  char ch;

  ch = 'a';
  while (ch <= 'z') {
    ft_putchar(ch);
    ch++;
  }
}

// int	main (void)
// {
// 	ft_print_alphabet ();
// }
