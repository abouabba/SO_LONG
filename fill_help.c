/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:39:47 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/11 03:32:42 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, int height)
{
	char	**map_copy;
	int		i;

	map_copy = malloc((height + 1) * sizeof(char *));
	if (!map_copy)
	{
		print_error("Error\nMemory allocation failed fot map copy");
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[height] = NULL;
	return (map_copy);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->copy[x][y] == '1' || game->copy[x][y] == 'F')
		return ;
	if (game->copy[x][y] == 'E')
	{
		game->copy[x][y] = 'F';
		return ;
	}
	game->copy[x][y] = 'F';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	check_valid_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->copy[i][j] == 'C' || game->copy[i][j] == 'E')
			{
				print_error("Error\n!In valid map");
				free_map(game->copy);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	free_image(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->empty)
		mlx_destroy_image(game->mlx, game->empty);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}

void free_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}