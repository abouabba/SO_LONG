/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:41:06 by abouabba          #+#    #+#             */
/*   Updated: 2025/02/22 17:36:32 by abouabba         ###   ########.fr       */
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

char **store_map_to_2d_array(char *file_name)
{
	int		fd;
	int		i;
	int		j;
	int		height;
	char	**map;
	char	*line;

	height = count_map_lines(file_name);
	i = 0;
	if (height <= 0)
		return (NULL);
	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
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
	t_game	h;
	t_game	w;
	t_game	game;
	
	if (ac != 2)
		return (1);
	if (!in_valid_ber_file(av[1]))
	{
		print_error("Error\n!file_name is not valid");
		return (1);
	}
	game.map = store_map_to_2d_array(av[1]);
	if (!game.map)
	{
		print_error("Error\n!in valid map");
		return (1);
	}
	h.height = count_map_lines(av[1]);
	w.width = ft_strlen(game.map[0]);
	if (!is_map_valid_by_walls(game.map, h.height, w.width) || !is_map_rectangular(game.map) || !is_map_valid_chars(game.map))
	{
		print_error("Error\n!in valid map");
		free_map(game.map);
		return (1);
	}
    game.mlx = mlx_init();
    game.win = mlx_new_window( game.mlx, 64 * 28, 13 * 64, "so_long");
	game.player = mlx_xpm_file_to_image(game.mlx, "./textures/player.xpm", &w.width, &h.height);
	game.collectible = mlx_xpm_file_to_image(game.mlx, "./textures/collectible.xpm", &w.width, &h.height);
	game.empty = mlx_xpm_file_to_image(game.mlx, "./textures/empty.xpm", &w.width, &h.height);
	game.exit = mlx_xpm_file_to_image(game.mlx, "./textures/door.xpm", &w.width, &h.height);
	game.wall = mlx_xpm_file_to_image(game.mlx, "./textures/wall.xpm", &w.width, &h.height);
	mlx_put_image_to_window(game.mlx, game.win, game.player, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.collectible, 200, 200);
	mlx_put_image_to_window(game.mlx, game.win, game.exit, 200, 300);
	mlx_put_image_to_window(game.mlx, game.win, game.empty, 130, 120);
	mlx_put_image_to_window(game.mlx, game.win, game.wall, 100, 100);
    mlx_loop(game.mlx);
	return (0);
}
