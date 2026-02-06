/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:38:07 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/30 14:38:46 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	set_player(t_cub *cub, char dir, int y, int x)
{
	if (cub->player.start_dir)
		error(cub, "multiple player positions");
	cub->player.start_dir = dir;
	cub->player.x = x + 0.5;
	cub->player.y = y + 0.5;
}

void	replace_player_by_zero(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_player(map->grid[y][x]))
				map->grid[y][x] = '0';
			x++;
		}
		y++;
	}
}
