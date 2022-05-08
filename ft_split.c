/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:50:45 by slonnie           #+#    #+#             */
/*   Updated: 2022/04/03 16:08:46 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_wordlen(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		++i;
	return (i);
}

int	count_words(char const *str, char c)
{
	int	num_words;

	num_words = 0;
	while (*str == c && *str)
		++str;
	while (*str)
	{
		++num_words;
		while (*str != c && *str)
			++str;
		while (*str == c && *str)
			++str;
	}
	return (num_words);
}

char	*word_dupe(char const *str, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_wordlen(str, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char const *str, char c)
{
	int	word_index;

	word_index = 0;
	while (*str == c && *str)
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str, c);
		if (!array[word_index] && array[0])
		{
			while (word_index != -1)
			{
				free(array[word_index]);
				array[word_index] = NULL;
				--word_index;
			}
			return ;
		}
		++word_index;
		while (*str != c && *str)
			++str;
		while (*str == c && *str)
			++str;
	}
}

char	**ft_split(char const *str, char c)
{
	int		num_words;
	char	**array;

	if (str == 0)
		return (0);
	num_words = count_words(str, c);
	array = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!array)
		return (0);
	array[num_words] = NULL;
	fill_words(array, str, c);
	return (array);
}
