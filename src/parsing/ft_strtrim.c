/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:07:46 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/22 14:19:23 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static size_t	checkset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_strlennew(const char *s1, const char *set, size_t *start_out)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !*s1)
	{
		*start_out = 0;
		return (0);
	}
	end = ft_strlen(s1);
	while (s1[start] && checkset(s1[start], set))
		start++;
	if (start == end)
	{
		*start_out = 0;
		return (0);
	}
	end--;
	while (end > start && checkset(s1[end], set))
		end--;
	*start_out = start;
	return (end - start + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*new;
	size_t	start;
	size_t	new_len;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	new_len = ft_strlennew(s1, set, &start);
	new = malloc(new_len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < new_len)
	{
		new[i] = s1[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
