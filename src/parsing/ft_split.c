/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:03:53 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/22 14:19:23 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void	free_all(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (src[len])
	{
		len++;
	}
	if (dest_size == 0)
		return (len);
	while (src[i] && i < dest_size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = malloc(len_word(s, c) * sizeof(char) + 1);
			if (!result[i])
				return (free_all(result, i), NULL);
			ft_strlcpy(result[i], s, len_word(s, c) + 1);
			s += len_word(s, c);
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}
