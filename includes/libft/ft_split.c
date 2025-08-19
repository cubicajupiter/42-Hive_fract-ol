/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:52:17 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/04 12:52:06 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **strings, unsigned int count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

static size_t	len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*fill_word(const char *src, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * size);
	while (i < size - 1)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	count_strings(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s == c)
		s++;
	if (*s)
	{
		while (*s)
		{
			if (*s == c)
			{
				while (*s == c)
					s++;
				if (!*s)
					return (count + 1);
				count++;
			}
			s++;
		}
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			**string_array;

	string_array = malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!string_array)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			string_array[j] = fill_word(&s[i], len(&s[i], c) + 1);
			if (!string_array[j])
				return (ft_free(string_array, j));
			j++;
			i += len(&s[i], c);
		}
	}
	string_array[j] = NULL;
	return (string_array);
}
