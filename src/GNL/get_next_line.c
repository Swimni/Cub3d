/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:48:44 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/22 14:19:23 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extractline(char *s)
{
	int		i;
	int		j;
	char	*line;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = s[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*clean(char *s)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (free(s), NULL);
	i++;
	rest = malloc(ft_strlen(s + i) + 1);
	if (rest == NULL)
		return (free(s), NULL);
	while (s[i])
	{
		rest[j] = s[i];
		j++;
		i++;
	}
	rest[j] = '\0';
	free(s);
	return (rest);
}

char	*read_and_yeah(int fd, char *yeah)
{
	char	*new;
	ssize_t	bytesread;
	char	*tmp;

	bytesread = 1;
	new = malloc(BUFFER_SIZE + 1);
	if (!new)
		return (free(yeah), NULL);
	while (!check(yeah) && bytesread > 0)
	{
		bytesread = read(fd, new, BUFFER_SIZE);
		if (bytesread == -1)
			return (free (new), free(yeah), NULL);
		if (bytesread == 0)
			break ;
		new[bytesread] = '\0';
		tmp = ft_strjoin(yeah, new);
		if (!tmp)
			return (free(new), free(yeah), NULL);
		yeah = tmp;
	}
	free(new);
	return (yeah);
}

char	*get_next_line(int fd)
{
	static char	*yeah;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	yeah = read_and_yeah(fd, yeah);
	if (!yeah)
		return (NULL);
	if (yeah[0] == '\0')
	{
		free(yeah);
		yeah = NULL;
		return (NULL);
	}
	line = extractline(yeah);
	yeah = clean(yeah);
	if (!line)
	{
		free(yeah);
		yeah = NULL;
		return (NULL);
	}
	return (line);
}
