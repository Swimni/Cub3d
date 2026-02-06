/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:44:50 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/22 14:19:23 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src && n > 0)
		return (0);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		d[i] = s [i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*new;
	size_t		len1;
	size_t		len2;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	new = NULL;
	new = malloc(len1 + len2 + 1);
	if (!new)
		return (free(s1), NULL);
	if (s1)
		ft_memcpy(new, s1, len1);
	if (s2)
		ft_memcpy(new + len1, s2, len2);
	new[len1 + len2] = '\0';
	free(s1);
	return (new);
}
