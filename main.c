/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:41:06 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/11 06:08:40 by abouabba         ###   ########.fr       */
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
	return (file_name[len - 4] == '.'
		&& file_name[len - 3] == 'b'
		&& file_name[len - 2] == 'e'
		&& file_name[len - 1] == 'r');
}

int	count_map_lines(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free (line);
	return (height);
}

void	position_player(t_game *game)
{
	int	i;
	int	j;

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

void	check_argument(int ac, char **av)
{
	if (ac != 2)
	{
		print_error("Error\n!In valid file");
		exit (1);
	}
	if (!in_valid_ber_file(av[1]))
	{
		print_error("Error\n!file_name is not valid");
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	check_argument(ac, av);
	game = malloc(sizeof(t_game));
	if (!game)
	{
		print_error("Error\n!Memory allocation failed");
		exit(1);
	}
	check_valide(av, game);
	position_player(game);
	flood_fill(game, game->x, game->y);
	check_valid_path(game);
	init_game(game);
	load_textures(game);
	render_map(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_loop(game->mlx);
	free_resources(game);
	return (0);
}
