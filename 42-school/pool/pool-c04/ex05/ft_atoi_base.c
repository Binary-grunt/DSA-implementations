/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:37:33 by codegrunt         #+#    #+#             */
/*   Updated: 2025/12/05 22:11:59 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // For NULL

/* Global error flags */
int g_base_error = 0;
int g_char_not_found = 0;

/* ************************************************************************** */
/*                           UTILITY FUNCTIONS                                */
/* ************************************************************************** */

/**
 * contains_char - Checks if a character exists in a given set of symbols.
 * @c: The character to check.
 * @symbols: The string containing the set of valid characters.
 *
 * Return: 1 if the character exists, 0 otherwise.
 */
int contains_char(char c, char *symbols)
{
	while (*symbols)
	{
		if (c == *symbols)
			return (1);
		symbols++;
	}
	return (0);
}

/**
 * is_whitespace - Checks if a character is a whitespace character.
 * @c: The character to check.
 *
 * Return: 1 if it's a whitespace, 0 otherwise.
 */
int is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

/**
 * power - Calculates the result of base^exp (base to the power of exp).
 * @base: The base number.
 * @exp: The exponent.
 *
 * Return: The result of the power calculation.
 */
int power(int base, int exp)
{
	if (exp < 0)
		return (0);
	if (exp == 0)
		return (1);
	return (base * power(base, exp - 1));
}

/**
 * has_duplicates - Checks if a string contains duplicate characters.
 * @symbols: The string to check.
 *
 * Return: 1 if duplicates are found, 0 otherwise.
 */
int has_duplicates(char *symbols)
{
	int i, j;

	for (i = 0; symbols[i]; i++)
	{
		for (j = i + 1; symbols[j]; j++)
		{
			if (symbols[i] == symbols[j])
				return (1);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                        BASE CONVERSION FUNCTIONS                          */
/* ************************************************************************** */

/**
 * compute_value - Recursively computes the numeric value of the number string.
 * @str: The current position in the number string.
 * @base: The set of symbols representing the base.
 * @base_len: The length of the base.
 * @position: The current position in the number string (from the rightmost digit).
 * @sign: The sign of the number (+1 or -1).
 *
 * Return: The numeric value represented by the string up to this position.
 */
int compute_value(char *str, char *base, int base_len, int position, int sign)
{
	int index = 0;

	/* Find the index of the current character in the base */
	while (str[0] != base[index])
		index++;

	/* If this is the last character, return its value */
	if (position == 0)
		return (index * sign);

	/* Otherwise, compute recursively */
	return (compute_value(str + 1, base, base_len, position - 1, sign) + (index * power(base_len, position) * sign));
}

/**
 * str_to_int_base - Converts a string representing a number in a given base
 *                   to its integer representation.
 * @str: The string to convert.
 * @base: The set of characters representing the base.
 *
 * Return: The integer value of the string, or 0 if an error occurs.
 */
int ft_atoi_base(char *str, char *base)
{
	int base_len = 0;
	int position = 0;
	int sign = 1;

	/* Validate the base */
	while (base[base_len])
	{
		if (base[base_len] == '+' || base[base_len] == '-' || is_whitespace(base[base_len]))
		{
			g_base_error = 1;
			return (0);
		}
		base_len++;
	}
	if (base_len < 2 || has_duplicates(base))
	{
		g_base_error = 1;
		return (0);
	}

	/* Skip leading whitespaces and signs */
	while (*str && (is_whitespace(*str) || *str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}

	/* Check that all characters in the string belong to the base */
	while (str[position])
	{
		if (!contains_char(str[position], base))
		{
			g_char_not_found = 1;
			return (0);
		}
		position++;
	}

	/* Convert the string to its integer value */
	return (compute_value(str, base, base_len, position - 1, sign));
}
