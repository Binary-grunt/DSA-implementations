/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                       :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 08:14:14 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/12/07 10:34:19 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* ************************************************************************** */
/*                           UTILITY FUNCTIONS                                */
/* ************************************************************************** */

/**
 * ft_strlen - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

/**
 * ft_strcat - Concatenates two strings.
 * @dest: The destination string (must have enough space).
 * @src: The source string to append to the destination.
 *
 * Return: The destination string after concatenation.
 */
char *ft_strcat(char *dest, char *src)
{
	int dest_size;
	int src_size;
	int idx;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	idx = 0;
	while (idx < src_size)
	{
		dest[dest_size + idx] = src[idx];
		idx++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                       CALCULATION FUNCTIONS                                */
/* ************************************************************************** */

/**
 * calculate_total_length - Computes the total length of the final string.
 * @count: The number of strings to join.
 * @strings: The array of strings to be joined.
 * @sep_len: The length of the separator.
 *
 * Return: The total length of the final string.
 */
int calculate_total_length(int count, char **strings, int sep_len)
{
	int total_len;
	int index;

	index = 0;
	total_len = 0;
	while (index < count)
	{
		total_len += ft_strlen(strings[index]);
		if (index != count - 1)
			total_len += sep_len;
		index++;
	}
	return (total_len);
}

/**
 * initialize_with_nulls - Fills a string with null bytes ('\0').
 * @buffer: The string to initialize.
 * @length: The number of null bytes to write.
 */
void initialize_with_nulls(char *buffer, int length)
{
	int idx;

	idx = 0;
	while (idx < length)
	{
		buffer[idx] = '\0';
		idx++;
	}
}

/* ************************************************************************** */
/*                         MAIN JOIN FUNCTION                                 */
/* ************************************************************************** */

/**
 * ft_strjoin - Joins an array of strings with a separator.
 * @size: The number of strings to join.
 * @strs: The array of strings to be joined.
 * @sep: The separator string to insert between the strings.
 *
 * Return: A newly allocated string containing all the joined strings,
 *         or an empty string if size == 0.
 */
char *ft_str_join(int size, char **strs, char *sep)
{
	int   separator_len;
	int   final_len;
	int   curr_idx;
	char *result;

	/* If size is 0, return an empty string */
	if (size == 0)
	{
		return (malloc(sizeof(char)));
	}

	/* Calculate lengths */
	separator_len = ft_strlen(sep);
	final_len = calculate_total_length(size, strs, separator_len);

	/* Allocate memory for the final string */
	result = malloc(final_len * sizeof(char) + 1);
	if (result == NULL)
	{
		return (NULL);
	}

	/* Initialize the allocated memory with null characters */
	initialize_with_nulls(result, final_len);

	/* Concatenate strings with the separator */
	curr_idx = 0;
	while (curr_idx < size)
	{
		ft_strcat(result, strs[curr_idx]);
		if (curr_idx != size - 1)
		{
			ft_strcat(result, sep);
		}
		curr_idx++;
	}
	result[final_len] = '\0';
	return (result);
}
