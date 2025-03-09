/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:42:10 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/09 08:26:49 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	store_map(int fd, char **map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
}

char **store_map_to_2d_array(char *file_name, int height)
{
	int		fd;
	char 	**map;

	height = count_map_lines(file_name);
	if (height <= 0)
	return (0);
	map = malloc((height + 1) * sizeof(char *));
	if (!map)
	return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		print_error("Error\n!Cannot open map file");
		return (NULL);
	}
	store_map(fd, map);
	close(fd);
	return (map);
}

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

int	is_map_valid_chars(t_game *game)
{
	int	i;
	int	j;
	
	i = -1;
	game->c_count = 0;
	game->P_count = 0;
	game->e_count = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				game->P_count++;
			else if (game->map[i][j] == 'E')
				game->e_count++;
			else if (game->map[i][j] == 'C')
				game->c_count++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				return (0);
		}
	}
	if (game->c_count < 1 || game->e_count != 1 || game->P_count != 1)
		return (0);
	return (1);
}
