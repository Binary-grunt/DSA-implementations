/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:27:33 by codegrunt         #+#    #+#             */
/*   Updated: 2025/12/05 22:11:59 by codegrunt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

/* ************************************************************************** */
/*                          UTILITY FUNCTIONS                                 */
/* ************************************************************************** */

/**
 * ft_puts - Prints a string followed by a newline to standard output.
 * @str: The string to print.
 */
void ft_puts(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

/**
 * ft_swap - Swaps the values of two string pointers.
 * @p1: Pointer to the first string.
 * @p2: Pointer to the second string.
 */
void ft_swap(char **p1, char **p2)
{
	char *tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/**
 * ft_strlen - Calculates the length of a string.
 * @str: The string whose length is to be calculated.
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
 * ft_putstr - Writes a string to standard output.
 * @str: The string to write.
 */
void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

/**
 * ft_strcmp - Compares two strings lexicographically.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A positive value if s1 > s2, 0 if s1 == s2, and a negative value if s1 < s2.
 */
int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

/* ************************************************************************** */
/*                           SORTING FUNCTION                                 */
/* ************************************************************************** */

/**
 * ft_sort_params - Sorts an array of strings in ascending order (lexicographical).
 * @argv: The array of strings to sort.
 * @count: The number of strings in the array.
 */
void ft_sort_params(char **argv, int count)
{
	int i;
	int j;
	int len;

	len = count;
	while (len > 1)
	{
		i = 0;
		j = 1;
		while (j < len)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				ft_swap(&argv[i], &argv[j]);
			i++;
			j++;
		}
		len--;
	}
}

/* ************************************************************************** */
/*                                MAIN FUNCTION                               */
/* ************************************************************************** */

/**
 * main - Entry point of the program. Sorts and prints program arguments.
 * @argc: The number of command-line arguments.
 * @argv: The array of command-line arguments.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char **argv)
{
	/* Sort arguments (excluding the program name) */
	ft_sort_params(argv + 1, argc - 1);

	/* Print the sorted arguments */
	while (*(++argv))
		ft_puts(*argv);
	return (0);
}
