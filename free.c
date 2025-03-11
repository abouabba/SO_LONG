/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:40:22 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/11 21:33:31 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
    if (map)
    {
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
}

void	free_resources(t_game *game)
{
	free_image(game);
	free_window(game);
	mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game->map)
		free_map(game->map);
	free(game);
}

void	ft_exit(t_game *game)
{
	if (game->height > 50 || game->width > 97)
	{
		free_map(game->map);
		free (game);
		print_error("Error\n!Map is too big\n");
		exit(1);
	}
	else if (game->c_count == 0)
	{
		ft_putnbr(game->move + 1);
		write (1, "\n", 1);
		free_resources(game);
		write (1, "you win!\n", 9);
		exit(0);
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

void	free_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}
