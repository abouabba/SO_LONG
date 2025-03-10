/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:58:39 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/10 15:38:13 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_valide(char **av, t_game *game)
{
	game->map = store_map_to_2d_array(av[1], game->height);
	if (!game->map)
	{
		print_error("Error\n!in valid map");
		free(game);
		exit (1);
	}
	game->height = 0;
	game->height = count_map_lines(av[1]);
	game->width = ft_strlen(game->map[0]);
	game->copy = copy_map(game->map, game->height);
	if (!is_map_valid_by_walls(game->map, game->height, game->width) ||
		!is_map_rectangular(game->map) || !is_map_valid_chars(game))
	{
		print_error("Error\n!In valid map");
		free_map(game->map);
		free(game);
		exit (1);
	}
}

int   handle_keypress(int keycode, t_game *game)
{
	printf ("key pressed: %d ---- %d\n", keycode,   game->c_count);
	if (keycode == KEY_W || keycode == UP) // W
		move_up(game);
	else if (keycode == KEY_D || keycode == RIGHT) // D
		move_right(game);
	else if (keycode == KEY_S || keycode == DOWN) // S
		move_down(game);
	else if (keycode == KEY_A || keycode == LEFT) // A
		move_left(game);
	else if (keycode == 65307) //Escape
	{
		free_map(game->map);
		free_map(game->copy);
		free(game);
		exit(0);
	}
	render_map(game);
	return(0); 
}
