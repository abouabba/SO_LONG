/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:58:39 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/15 14:58:38 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_valide(char **av, t_game *game)
{
	game->map = store_map_to_2d_array(av[1], game->height);
	if (!game->map)
	{
		free(game);
		print_error("Error\n----<!in valid map---->");
		exit (1);
	}
	game->height = count_map_lines(av[1]);
	game->width = ft_strlen(game->map[0]);
	if (game->height > 50 || game->width > 97)
		ft_exit(game);
	game->copy = copy_map(game->map, game->height);
	if (!is_map_valid_by_walls(game)
		|| !is_map_rectangular(game) || !is_map_valid_chars(game))
	{
		print_error("Error\n----<!in valid map---->");
		free_map(game->map);
		free_map(game->copy);
		free(game);
		exit (1);
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == UP)
		move_up(game);
	else if (keycode == KEY_D || keycode == RIGHT)
		move_right(game);
	else if (keycode == KEY_S || keycode == DOWN)
		move_down(game);
	else if (keycode == KEY_A || keycode == LEFT)
		move_left(game);
	else if (keycode == 65307)
	{
		free_resources(game);
		exit(0);
	}
	game->pointd = ft_itoa(game->move);
	render_map(game);
	mlx_string_put(game->mlx, game->win, 10, 30, 0x0000FF00, "Moves :");
    mlx_string_put(game->mlx, game->win, 60, 30, 0x0000FF00, game->pointd);
	free(game->pointd);
	game->pointd = NULL;
	return (0);
}

int	close_window(t_game *game)
{
	free_resources(game);
	exit(0);
}
