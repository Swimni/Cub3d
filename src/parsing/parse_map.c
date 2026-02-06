/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:57:16 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/30 15:00:20 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01NSEW", line[1]))
			return (0);
		i++;
	}
	return (1);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	parse_map_line(t_cub *cub, char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (is_player(line[i]))
		{
			set_player(cub, line[i], cub->map.height, i);
			replace_player_by_zero(&cub->map);
		}
		i++;
	}
	cub->map.grid = add_line(cub->map.grid, line);
	cub->map.height++;
	len = ft_strlen(line);
	if (len > cub->map.width)
		cub->map.width = len;
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	len = 0;
	while (s[len])
		len++;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**add_line(char **grid, char *line)
{
	int		i;
	char	**new;
	int		len;

	len = tablen(grid);
	i = 0;
	new = malloc(sizeof(char *) * (len + 2));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = grid[i];
		i++;
	}
	new[i] = ft_strdup(line);
	if (!new[i])
	{
		free(new);
		return (NULL);
	}
	new[i + 1] = NULL;
	free(grid);
	return (new);
}
