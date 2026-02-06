/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:01:25 by nguinot-          #+#    #+#             */
/*   Updated: 2026/01/30 13:32:03 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	init_player(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.grid[i])
	{
		j = 0;
		while (cub->map.grid[i][j])
		{
			if (cub->map.grid[i][j] == 'N' || cub->map.grid[i][j] == 'S'
				|| cub->map.grid[i][j] == 'E' || cub->map.grid[i][j] == 'W')
			{
				cub->player.x = j + 0.5;
				cub->player.y = i + 0.5;
				cub->player.start_dir = cub->map.grid[i][j];
				set_direction(cub, cub->player.start_dir);
				return ;
			}
			j++;
		}
		i++;
	}
	printf("Erreur: aucun spawn trouve\n");
	exit(1);
}

static void	player_e(t_cub *cub)
{
	cub->player.dir_x = 1.0;
	cub->player.dir_y = 0.0;
	cub->player.plane_x = 0.0;
	cub->player.plane_y = 0.66;
}

void	set_direction(t_cub *cub, char d)
{
	if (d == 'N')
	{
		cub->player.dir_x = 0.0;
		cub->player.dir_y = -1.0;
		cub->player.plane_x = 0.66;
		cub->player.plane_y = 0.0;
	}
	else if (d == 'S')
	{
		cub->player.dir_x = 0.0;
		cub->player.dir_y = 1.0;
		cub->player.plane_x = -0.66;
		cub->player.plane_y = 0.0;
	}
	else if (d == 'W')
	{
		cub->player.dir_x = -1.0;
		cub->player.dir_y = 0.0;
		cub->player.plane_x = 0.0;
		cub->player.plane_y = -0.66;
	}
	else if (d == 'E')
		player_e(cub);
}
