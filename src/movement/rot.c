/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:14:50 by nguinot-          #+#    #+#             */
/*   Updated: 2026/01/30 13:28:37 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	rotate_player(t_cub *cub, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(rot_speed) - cub->player.dir_y
		* sin(rot_speed);
	cub->player.dir_y = old_dir_x * sin(rot_speed) + cub->player.dir_y
		* cos(rot_speed);
	old_plane_x = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x
		* cos(rot_speed)
		- cub->player.plane_y * sin(rot_speed);
	cub->player.plane_y = old_plane_x * sin(rot_speed) + cub->player.plane_y
		* cos(rot_speed);
}
