/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:41:06 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/09 01:23:24 by abouabba         ###   ########.fr       */
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
	if (height <= 0)
	return (0);
	map = malloc((height + 1) * sizeof(char *));
	if (!map)
	return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	int k = ft_strlen(line);
	while (line)
	{
		j = ft_strlen(line);
		if (k == j)
			line[j - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
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
			j++;
		}
		i++;
	}
}
void f(t_game *game)
{
	int i = 0, j = 0;;
	while (i < game->height)
	{
		j = 0;
		while (j <= game->width)
		{
			if (game->copy[i][j] == '\0')
				game->copy[i][j] = '\n';
			printf("%c", game->copy[i][j]);
			j++;
		}
		i++;
	}
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
	if (!game)
		return (1);
	game->map = store_map_to_2d_array(av[1], game->height);
	if (!game->map)
	{
		print_error("Error\n!in valid map");
		free(game);
		return (1);
	}
	game->height = count_map_lines(av[1]);
	game->width = ft_strlen(game->map[0]);
	game->copy = copy_map(game->map, game->height);
	if (!is_map_valid_by_walls(game->map, game->height, game->width) ||
		!is_map_rectangular(game->map) || !is_map_valid_chars(game->map))
	{
		print_error("Error\n!In valid map");
		free_map(game->map);
		free(game);
		return (1);
	}
	position_player(game);
	flood_fill(game, game->x, game->y);
	check_valid_path(game);
	f(game);
	free_map(game->map);
	free_map(game->copy);
	free (game);
	return (0);
}

