/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:57:09 by mbuisson          #+#    #+#             */
/*   Updated: 2026/02/03 12:10:11 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	is_texture(char *line)
{
	return (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3));
}

void	set_texture(t_cub *cub, char *id, char *path)
{
	int	index;

	index = 0;
	if (!ft_strcmp(id, "NO"))
		index = NO;
	else if (!ft_strcmp(id, "SO"))
		index = SO;
	else if (!ft_strcmp(id, "EA"))
		index = EA;
	else if (!ft_strcmp(id, "WE"))
		index = WE;
	else
		error(cub, "Unknown texture identifier");
	if (cub->textures[index].path)
		error(cub, "Duplicate texture");
	cub->textures[index].path = ft_strdup(path);
}

void	parse_texture(t_cub *cub, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (count_tab(split) != 2)
		error(cub, "Invalid texture line");
	set_texture(cub, split[0], split[1]);
	free_tab(split);
}

void	free_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->textures[i].path)
			free(cub->textures[i].path);
		i++;
	}
}
