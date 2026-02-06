/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:32:12 by nguinot-          #+#    #+#             */
/*   Updated: 2026/01/30 13:27:53 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	move_forward(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.x + cub->player.dir_x * cub->move_speed;
	new_y = cub->player.y + cub->player.dir_y * cub->move_speed;
	if (cub->map.grid[(int)cub->player.y][(int)new_x] != '1')
		cub->player.x = new_x;
	if (cub->map.grid[(int)new_y][(int)cub->player.x] != '1')
		cub->player.y = new_y;
}

void	move_backward(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.x - cub->player.dir_x * cub->move_speed;
	new_y = cub->player.y - cub->player.dir_y * cub->move_speed;
	if (cub->map.grid[(int)cub->player.y][(int)new_x] != '1')
		cub->player.x = new_x;
	if (cub->map.grid[(int)new_y][(int)cub->player.x] != '1')
		cub->player.y = new_y;
}

void	move_right(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.x - cub->player.dir_y * cub->move_speed;
	new_y = cub->player.y + cub->player.dir_x * cub->move_speed;
	if (cub->map.grid[(int)cub->player.y][(int)new_x] != '1')
		cub->player.x = new_x;
	if (cub->map.grid[(int)new_y][(int)cub->player.x] != '1')
		cub->player.y = new_y;
}

void	move_left(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.x + cub->player.dir_y * cub->move_speed;
	new_y = cub->player.y - cub->player.dir_x * cub->move_speed;
	if (cub->map.grid[(int)cub->player.y][(int)new_x] != '1')
		cub->player.x = new_x;
	if (cub->map.grid[(int)new_y][(int)cub->player.x] != '1')
		cub->player.y = new_y;
}
