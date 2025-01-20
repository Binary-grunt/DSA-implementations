/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:37:33 by codegrunt         #+#    #+#             */
/*   Updated: 2025/12/05 22:11:59 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

/* ************************************************************************** */
/*                            UTILITY FUNCTIONS                               */
/* ************************************************************************** */

/**
 * ft_strlen - Returns the length of a string.
 * @str: The string to measure.
 *
 * Return: The length of the string.
 */
int ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (1 + ft_strlen(str + 1));
}

/**
 * bad_base - Checks if a base is invalid.
 * @base: The string representing the base.
 *
 * Return: 1 if the base is invalid, 0 otherwise.
 */
int bad_base(char *base)
{
	int i;
	int j;

	/* A base is invalid if it has fewer than 2 characters */
	if (!base || base[0] == '\0' || base[1] == '\0')
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		/* Check for invalid characters '-' and '+' */
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = i + 1;
		/* Check for duplicate characters in the base */
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                            MAIN FUNCTION                                   */
/* ************************************************************************** */

/**
 * ft_putnbr_base - Prints a number using a given base.
 * @nbr: The number to print.
 * @base: The string representing the base to use.
 *
 * Return: The number of characters printed, or 0 if the base is invalid.
 */
ssize_t ft_putnbr_base(uintptr_t nbr, char *base)
{
	ssize_t count;
	size_t  base_len;

	/* Check if the base is invalid */
	if (bad_base(base))
		return (0);
	count = 0;
	base_len = ft_strlen(base);

	/* Handle negative numbers */
	if ((long) nbr < 0)
	{
		count += write(1, "-", 1);
		count += ft_putnbr_base(-nbr, base);
		return (count);
	}

	/* Recursive call to handle larger numbers */
	if (nbr >= base_len)
		count += ft_putnbr_base(nbr / base_len, base);

	/* Write the current digit */
	count += write(1, &base[nbr % base_len], 1);

	return (count);
}
