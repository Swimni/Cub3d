/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:57:00 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/30 14:43:32 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static void	do_texture(t_cub *cub, char *trimmed)
{
	if (cub->parsing.map_finished)
		error(cub, "Texture after map");
	parse_texture(cub, trimmed);
}

static void	do_color(t_cub *cub, char *trimmed)
{
	if (cub->parsing.map_finished)
		error(cub, "Color after map");
	parse_color(cub, trimmed);
}

void	parse_line(t_cub *cub, char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \n");
	if (!trimmed)
		error(cub, "Malloc failed");
	if (!trimmed[0])
	{
		if (cub->parsing.in_map)
			cub->parsing.map_finished = 1;
		return (free(trimmed));
	}
	if (cub->parsing.map_finished)
		error(cub, "Invalid content after map");
	if (is_texture(trimmed))
		do_texture(cub, trimmed);
	else if (is_color(trimmed))
		do_color(cub, trimmed);
	else if (is_map_line(trimmed))
	{
		cub->parsing.in_map = 1;
		parse_map_line(cub, trimmed);
	}
	else
		error(cub, "Invalid line in .cub file");
	free(trimmed);
}

void	parse_cub(t_cub *cub, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error(cub, "Cannot open file");
	init_data(cub);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(cub, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_parsing_complete(cub);
	normalize_map(&cub->map);
	check_map(cub);
}

void	check_parsing_complete(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!cub->textures[i].path)
			error(cub, "Missing texture");
		i++;
	}
	if (cub->ceiling_color == -1 || cub->floor_color == -1)
		error(cub, "Missing floor or ceiling color");
	if (!cub->player.start_dir)
		error(cub, "Missing player");
	if (!cub->map.grid || cub->map.height == 0)
		error(cub, "Missing map");
}
