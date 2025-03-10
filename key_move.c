/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:01:15 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/10 12:15:33 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(t_game *game)
{
	if (game->map[game->x - 1][game->y] != '1')
		game->x--;
}

void move_right(t_game *game)
{
	if (game->map[game->x][game->y + 1] != '1')
		game->y++;
}

void move_down(t_game *game)
{
	if (game->map[game->x + 1][game->y] != '1')
		game->x++;
}

void move_left(t_game *game)
{
	if (game->map[game->x][game->y - 1] != '1')
		game->y--;
}
