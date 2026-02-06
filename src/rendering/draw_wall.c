/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:20:34 by nguinot-          #+#    #+#             */
/*   Updated: 2026/01/30 15:04:51 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static void	calculate_limits(t_ray *ray, int *line_height, int *draw_start,
		int *draw_end)
{
	*line_height = (int)(WIN_H / ray->perp_wall_dist);
	*draw_start = -(*line_height) / 2 + WIN_H / 2;
	*draw_end = (*line_height) / 2 + WIN_H / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	if (*draw_end >= WIN_H)
		*draw_end = WIN_H - 1;
}

static int	calculate_tex_x(t_cub *cub, t_ray *ray, t_tex *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = cub->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = cub->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	return (tex_x);
}

static void	draw_vertical_line(t_cub *cub, t_draw_data *data, int x)
{
	int	y;
	int	tex_y;
	int	color;

	y = data->draw_start;
	while (y < data->draw_end)
	{
		tex_y = (int)data->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= data->tex->height)
			tex_y = data->tex->height - 1;
		data->tex_pos += data->step;
		color = *(unsigned int *)(data->tex->addr + tex_y * data->tex->line_len
				+ data->tex_x * (data->tex->bpp / 8));
		my_mlx_pixel_put(cub, x, y, color);
		y++;
	}
}

void	draw_wall(t_cub *cub, t_ray *ray, int x)
{
	t_draw_data	data;
	int			line_height;

	data.tex = get_wall_texture(cub, ray);
	calculate_limits(ray, &line_height, &data.draw_start, &data.draw_end);
	data.tex_x = calculate_tex_x(cub, ray, data.tex);
	data.step = (double)data.tex->height / line_height;
	data.tex_pos = (data.draw_start - WIN_H / 2 + line_height / 2) * data.step;
	draw_vertical_line(cub, &data, x);
}
