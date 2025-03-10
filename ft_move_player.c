/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:58:39 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/10 11:58:59 by abouabba         ###   ########.fr       */
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
	if (keycode == 119) // W
		move_up(game);
	if (keycode == 100) // D
		move_right(game);
	if (keycode == 115) // S
		move_down(game);
	if (keycode == 97) // A
		move_left(game);
	if (keycode == 65307) //esc
		exit(1);
	return(0); 
}
