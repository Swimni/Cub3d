/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:06:14 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/30 15:07:58 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	draw_line(t_cub *cub, t_line *line)
{
	t_line_calc	c;

	c.i = 0;
	c.x = line->x0;
	c.y = line->y0;
	c.x_inc = (line->x1 - line->x0);
	c.y_inc = (line->y1 - line->y0);
	if (ft_abs(c.x_inc) > ft_abs(c.y_inc))
		c.steps = ft_abs(c.x_inc);
	else
		c.steps = ft_abs(c.y_inc);
	if (c.steps == 0)
		return ;
	c.x_inc /= c.steps;
	c.y_inc /= c.steps;
	while (c.i <= c.steps)
	{
		put_pixel(cub, (int)c.x, (int)c.y, line->color);
		c.x += c.x_inc;
		c.y += c.y_inc;
		c.i++;
	}
}

void	init_square_wall(t_square *square, int x, int y)
{
	square->x = MM_X + x * MM_SCALE;
	square->y = MM_Y + y * MM_SCALE;
	square->size = MM_SCALE;
	square->color = 0x444444;
}

void	init_square_walk(t_square *square, int x, int y)
{
	square->x = MM_X + x * MM_SCALE;
	square->y = MM_Y + y * MM_SCALE;
	square->size = MM_SCALE;
	square->color = 0xCCCCCC;
}

void	draw_minimap(t_cub *cub)
{
	int			y;
	int			x;
	t_square	square;

	y = 0;
	while (cub->map.grid[y])
	{
		x = 0;
		while (cub->map.grid[y][x])
		{
			if (cub->map.grid[y][x] == '1')
			{
				init_square_wall(&square, x, y);
				draw_square(cub, &square);
			}
			else
			{
				init_square_walk(&square, x, y);
				draw_square(cub, &square);
			}
			x++;
		}
		y++;
	}
}
