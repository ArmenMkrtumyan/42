/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:04:27 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/17 14:48:37 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	fill_interval(int start, int end, char const *s, char *out)
{
	int	i;

	i = 0;
	while (start < end)
	{
		out[i] = s[start];
		i++;
		start++;
	}
	out[i] = '\0';
}

static void	for_sake_of_norm(bool *word, int *words,
		int *end_location, size_t *j)
{
	*word = false;
	*words = *words + 1;
	*end_location = *j;
}

static void	get_interval(int i, char const *s, char c, int *interval)
{
	bool	word;
	int		words;
	size_t	j;
	int		start_location;
	int		end_location;

	word = false;
	j = -1;
	words = 0;
	while (++j <= ft_strlen(s))
	{
		if (!word && (s[j] != c && s[j] != '\0' ))
		{
			word = true;
			start_location = j;
		}
		if ((s[j] == c || s[j] == '\0') && word)
			for_sake_of_norm(&word, &words, &end_location, &j);
		if (words == i)
		{
			interval[0] = start_location;
			interval[1] = end_location;
			return ;
		}
	}
}

static int	calculate_words(char const *s, char c)
{
	size_t	i;
	int		words;
	bool	word;

	i = 0;
	words = 0;
	word = false;
	while (i <= ft_strlen(s))
	{
		if (!word && (s[i] != c && s[i] != '\0'))
			word = true;
		if ((s[i] == c || s[i] == '\0') && word)
		{
			word = false;
			words++;
		}
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		word_count;
	int		i;
	int		*interval;

	if (!s)
		return (NULL);
	word_count = calculate_words(s, c);
	out = (char **)malloc((word_count + 1) * sizeof(char *));
	interval = (int *)malloc(sizeof(int) * 3);
	i = 1;
	while (i - 1 < word_count)
	{
		get_interval(i, s, c, interval);
		interval[2] = '\0';
		out[i - 1] = (char *)malloc(sizeof(char)
				* (interval[1] - interval[0] + 1));
		fill_interval(interval[0], interval[1], s, out[i - 1]);
		i++;
	}
	free(interval);
	out[i - 1] = NULL;
	return (out);
}
