/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:24:57 by nguinot-          #+#    #+#             */
/*   Updated: 2026/01/21 11:21:31 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	raycasting(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		init_ray(cub, &cub->ray, x);
		calc_step_and_side_dist(cub, &cub->ray);
		perform_dda(cub, &cub->ray);
		calc_wall_distance(&cub->ray);
		draw_wall(cub, &cub->ray, x);
		x++;
	}
}
