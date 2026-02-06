/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:48:05 by nguinot-          #+#    #+#             */
/*   Updated: 2026/02/03 10:57:28 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == 119)
		cub->key_w = 1;
	if (keycode == 115)
		cub->key_s = 1;
	if (keycode == 97)
		cub->key_a = 1;
	if (keycode == 100)
		cub->key_d = 1;
	if (keycode == 65361)
		cub->key_right = 1;
	if (keycode == 65363)
		cub->key_left = 1;
	if (keycode == 101)
		cub->key_e = 1;
	if (keycode == 65307)
		close_window(cub);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == 119)
		cub->key_w = 0;
	if (keycode == 115)
		cub->key_s = 0;
	if (keycode == 97)
		cub->key_a = 0;
	if (keycode == 100)
		cub->key_d = 0;
	if (keycode == 65361)
		cub->key_right = 0;
	if (keycode == 65363)
		cub->key_left = 0;
	return (0);
}

int	update_player(t_cub *cub)
{
	double	rotate_speed;

	rotate_speed = 0.01;
	if (cub->key_w)
		move_forward(cub);
	if (cub->key_s)
		move_backward(cub);
	if (cub->key_a)
		move_left(cub);
	if (cub->key_d)
		move_right(cub);
	if (cub->key_left)
		rotate_player(cub, rotate_speed);
	if (cub->key_right)
		rotate_player(cub, -rotate_speed);
	render_frame(cub);
	return (0);
}
