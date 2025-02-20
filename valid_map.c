/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:42:10 by abouabba          #+#    #+#             */
/*   Updated: 2025/02/20 11:03:22 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_valid_by_walls(char **map, int height, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_rectangular(char **map)
{
	int	i;
	int width;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_valid_chars(char **map)
{
	int	i;
	int	j;
	int	c_count;
	int	P_count;
	int	e_count;
	
	i = 0;
	c_count = 0;
	P_count = 0;
	e_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				P_count++;
			else if (map[i][j] == 'E')
				e_count++;
			else if (map[i][j] == 'C')
				c_count++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	if (c_count < 1 || e_count != 1 || P_count != 1)
		return (0);
	return (1);
	
}
