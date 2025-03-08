/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:41:06 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/08 03:36:31 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	in_valid_ber_file(char *file_name)
{
	int	len;

	if (!file_name)
		return (0);
	len = 0;
	while (file_name[len])
		len++;
	if (len < 4)
		return (0);
	return (file_name[len - 4] == '.' &&
			file_name[len - 3] == 'b' &&
			file_name[len - 2] == 'e' &&
			file_name[len - 1] == 'r');
}

int count_map_lines(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	height= 0;
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

char **store_map_to_2d_array(char *file_name, int height)
{
	int		fd;
	int		i;
	int		j;
	char 	**map;
	char	*line;

	height = count_map_lines(file_name);
	i = 0;
	if (height <= 0)
		return (0);
	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	int k = ft_strlen(line);
	while (line)
	{
		j = ft_strlen(line);
		if (k == j)
			line[j - 1] =  '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int main (int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		print_error("Error\n!In valid file");
		return (1);
	}
	if (!in_valid_ber_file(av[1]))
	{
		print_error("Error\n!file_name is not valid");
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (game)
		return (1);
	game->map = store_map_to_2d_array(av[1], game->height);
	if (!game->map)
	{
		print_error("Error\n!in valid map");
		return (1);
	}
	game->height = count_map_lines(av[1]);
	game->width = ft_strlen(game->map[0]);
	game->copy = copy_map(game->map, game->height);
	if (!is_map_valid_by_walls(game->map, game->height, game->width) || !is_map_rectangular(game->map) || !is_map_valid_chars(game->map))
	{
		print_error("Error\n!In valid map");
		free_map(game->map);
		return (1);
	}
	position_player(game);
	game->x = 2;
	game->y = 1;
	flood_fill(game->copy, game->x, game->y);
	check_valid_path(game->copy, game->height, game->width);
	return (0);
}

void position_player(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->x = i;
				game->y = j;
			}
			if (game->map[i][j] == 'C')
				game.
		}
		
	}
	
}