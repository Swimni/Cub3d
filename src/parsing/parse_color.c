/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:25 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/22 14:43:48 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	is_color(char *line)
{
	if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
		return (1);
	return (0);
}

void	check_rgb(t_cub *cub, char **rgb)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	value = 0;
	while (i < 3)
	{
		if (!rgb[i][0])
			error(cub, "Empty RGB value");
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_is_digit(rgb[i][j]))
				error(cub, "Value must be a digit");
			j++;
		}
		value = ft_atoi(rgb[i]);
		if (value < 0 || value > 255)
			error(cub, "RGB value out of range");
		i++;
	}
}

void	parse_color(t_cub *cub, char *line)
{
	char	**split;
	char	**rgb;

	split = ft_split(line, ' ');
	if (count_tab(split) != 2)
		error(cub, "Invalid color format");
	rgb = ft_split(split[1], ',');
	if (count_tab(rgb) != 3)
		error(cub, "Invalid RGB value");
	check_rgb(cub, rgb);
	set_color(cub, split[0][0], rgb);
	free_tab(rgb);
	free_tab(split);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	set_color(t_cub *cub, char id, char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error(cub, "RGB out of range");
	if (id == 'F')
	{
		if (cub->floor_color != -1)
			error(cub, "Duplicate floor color");
		cub->floor_color = rgb_to_int(r, g, b);
	}
	else if (id == 'C')
	{
		if (cub->ceiling_color != -1)
			error(cub, "Duplicate ceilling color");
		cub->ceiling_color = rgb_to_int(r, g, b);
	}
}
