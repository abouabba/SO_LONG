/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:35:02 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/15 17:18:04 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error\n<----!MLX initilization failed---->");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * 40,
			game->height * 40, "./so_long");
	if (!game->win)
	{
		perror("Error\n<----!Window creation failed---->");
		exit(1);
	}
}

void	load_textures(t_game *game)
{
	int	height;
	int	width;

	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->empty = mlx_xpm_file_to_image(game->mlx,
			"textures/empty.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	if (!game->exit || !game->collectible || !game->empty
		|| !game->player || !game->wall)
	{
		free_resources(game);
		perror("Error\n<----!Texture loading failed---->");
		exit(1);
	}
}

void	render_map_2(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->wall, y * 40, x * 40);
	else if (game->map[x][y] == '0')
		mlx_put_image_to_window(game->mlx,
			game->win, game->empty, y * 40, x * 40);
	else if (game->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible, y * 40, x * 40);
	else if (game->map[x][y] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, y * 40, x * 40);
	else if (game->map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->exit, y * 40, x * 40);
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
			render_map_2(game, x, y);
			y++;
		}
		x++;
	}
}
