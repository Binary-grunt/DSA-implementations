/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codegrunt <codegrunt@proton.me>	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:11:44 by codegrunt	       #+#    #+#             */
/*   Updated: 2024/12/07 14:24:29 by codegrunt	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* ************************************************************************** */
/*                          UTILITY FUNCTIONS                                 */
/* ************************************************************************** */

/**
 * ft_is_space - Checks if a character is part of the delimiter set.
 * @to_find: The character to check.
 * @charset: The string containing delimiter characters.
 *
 * Return: 1 if the character is found in the delimiter set, 0 otherwise.
 */
int ft_is_space(char to_find, char *charset)
{
	while (*charset)
	{
		if (to_find == *charset++)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * ft_wordcount - Counts the number of words in a string, separated by delimiters.
 * @str: The input string to analyze.
 * @charset: The string containing delimiter characters.
 *
 * Return: The number of words in the string.
 */
int ft_wordcount(char *str, char *charset)
{
	int word_count;

	word_count = 0;
	while (*str)
	{
		/* Skip delimiter characters */
		while (*str && ft_is_space(*str, charset))
		{
			str++;
		}
		/* If we find a word, increase the word count */
		if (*str && !ft_is_space(*str, charset))
		{
			word_count++;
			while (*str && !ft_is_space(*str, charset))
				str++;
		}
	}
	return (word_count);
}

/**
 * create_word - Allocates memory and creates a single word from the input string.
 * @str: The input string.
 * @start: The starting index of the word.
 * @end: The ending index of the word (exclusive).
 *
 * Return: A pointer to the newly allocated word, or NULL on failure.
 */
char *create_word(char *str, int start, int end)
{
	char *word;
	int   letter_idx;

	letter_idx = 0;
	word = (char *) malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
	{
		return (NULL);
	}
	while (start < end)
	{
		word[letter_idx] = str[start];
		start++;
		letter_idx++;
	}
	word[letter_idx] = '\0';
	return (word);
}

/* ************************************************************************** */
/*                           MAIN SPLIT FUNCTION                              */
/* ************************************************************************** */

/**
 * ft_split - Splits a string into an array of words, separated by delimiters.
 * @str: The input string to split.
 * @charset: The string containing delimiter characters.
 *
 * Return: A NULL-terminated array of strings (words), or NULL on failure.
 */
char **ft_split(char *str, char *charset)
{
	char **result;
	int    word_count;
	int    curr_word;
	int    start;
	int    end;

	/* Count the total number of words in the input string */
	word_count = ft_wordcount(str, charset);

	/* Allocate memory for the array of words */
	result = (char **) malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
	{
		return (NULL);
	}

	curr_word = 0;
	start = 0;
	while (curr_word < word_count)
	{
		/* Skip delimiter characters to find the start of a word */
		while (ft_is_space(str[start], charset) && str[start])
			start++;
		end = start;

		/* Find the end of the current word */
		while (!ft_is_space(str[end], charset) && str[end])
			end++;

		/* Allocate and store the current word */
		result[curr_word] = create_word(str, start, end);

		/* Move to the next word */
		start = end + 1;
		curr_word++;
	}

	/* Null-terminate the result array */
	result[curr_word] = NULL;
	return (result);
}
