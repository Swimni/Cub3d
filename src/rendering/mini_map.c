/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:32:20 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/30 15:06:56 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = cub->addr + (y * cub->line_len + x * (cub->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_cub *cub, t_square *square)
{
	int	i;
	int	j;

	i = 0;
	while (i < square->size)
	{
		j = 0;
		while (j < square->size)
		{
			put_pixel(cub, square->x + j, square->y + i, square->color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_cub *cub, t_circle *circle)
{
	int	x;
	int	y;

	y = -circle->radius;
	while (y <= circle->radius)
	{
		x = -circle->radius;
		while (x <= circle->radius)
		{
			if (x * x + y * y <= circle->radius * circle->radius)
				put_pixel(cub, circle->cx + x, circle->cy + y, circle->color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_cub *cub)
{
	t_circle	circle;

	circle.cx = MM_X + cub->player.x * MM_SCALE;
	circle.cy = MM_Y + cub->player.y * MM_SCALE;
	circle.radius = 3;
	circle.color = 0xFF0000;
	draw_circle(cub, &circle);
}
