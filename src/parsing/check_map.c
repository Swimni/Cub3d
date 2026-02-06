/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:57:23 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/30 15:02:07 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static void	while_j(int i, int len, char *new, t_map *map)
{
	int	j;

	j = 0;
	while (j < map->width)
	{
		if (j < len)
			new[j] = map->grid[i][j];
		else
			new[j] = ' ';
		j++;
	}
	new[j] = '\0';
}

void	normalize_map(t_map *map)
{
	int		i;
	int		len;
	char	*new;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (!map->grid[i])
			return ;
		len = ft_strlen(map->grid[i]);
		new = malloc(sizeof(char) * (map->width + 1));
		if (!new)
			return ;
		while_j(i, len, new, map);
		free(map->grid[i]);
		map->grid[i] = new;
		i++;
	}
}

int	is_walkable(char c)
{
	if (c == '0' || is_player(c))
		return (1);
	return (0);
}

void	check_map_closed(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			if (is_walkable(cub->map.grid[y][x]))
			{
				if (y == 0 || x == 0 || y == cub->map.height - 1
					|| x == cub->map.width - 1)
					error(cub, "Map not closed (open border)");
				if (cub->map.grid[y][x - 1] == ' ' || cub->map.grid[y][x
					+ 1] == ' ' || cub->map.grid[y - 1][x] == ' '
					|| cub->map.grid[y + 1][x] == ' ')
					error(cub, "Map not closed (hole)");
			}
			x++;
		}
		y++;
	}
}

void	check_map_char(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			if (!ft_strchr("01 NSEW", cub->map.grid[y][x]))
				error(cub, "Invalid chararcter in map");
			x++;
		}
		y++;
	}
}
