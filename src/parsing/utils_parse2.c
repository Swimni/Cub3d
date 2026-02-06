/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:15:43 by mbuisson          #+#    #+#             */
/*   Updated: 2026/01/22 14:52:04 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	count_tab(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_data(t_cub *cub)
{
	int	i;

	if (!cub)
		return ;
	i = 0;
	while (i < 4)
	{
		if (cub->textures[i].path)
			free(cub->textures[i].path);
		i++;
	}
	if (cub->map.grid)
		free_tab(cub->map.grid);
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * j);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((s1[i]) || (s2[i])) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}
