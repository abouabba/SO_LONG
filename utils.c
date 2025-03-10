/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:35:02 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/10 13:25:38 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void print_error(char *msg)
{
	write (2, msg, ft_strlen(msg));
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		print_error("Error\n!MLX initilization failed");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * 40, game->height * 40, "so_long");
	if (!game->win)
	{
		print_error("Error\n!Window creation failed");
		exit(1);
	}
}

void	load_textures(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->width, &game->height);
	game->empty = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm", &game->width, &game->height);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->width, &game->height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &game->width, &game->height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->width, &game->height);
	if (!game->wall || !game->collectible || !game->empty || !game->exit || !game->player)
	{
		print_error("Error\n!failed to load textures");
		exit(1);
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, y * 40, x * 40);
			else if (game->map[x][y] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->empty, y * 40, x * 40);
			else if (game->map[x][y] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible, y * 40, x * 40);
			else if (game->map[x][y] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player, y * 40, x * 40);
			else if (game->map[x][y] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, y * 40, x * 40);
			y++;
		}
		x++;
	}
}
