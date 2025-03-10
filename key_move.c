/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:01:15 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/10 13:40:48 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(t_game *game)
{
	if (game->map[game->x - 1][game->y] != '1')
	{
		game->map[game->x][game->y] = '0';
		game->x--;
		game->map[game->x][game->y] = 'P';
	}
}

void move_right(t_game *game)
{
	if (game->map[game->x][game->y + 1] != '1')
	{
		game->map[game->x][game->y] = '0';
		game->y++;
		game->map[game->x][game->y] = 'P';
	}
}

void move_down(t_game *game)
{
	if (game->map[game->x + 1][game->y] != '1')
	{
		game->map[game->x][game->y] = '0';
		game->x++;
		game->map[game->x][game->y] = 'P';
	}
}

void move_left(t_game *game)
{
	if (game->map[game->x][game->y - 1] != '1')
	{
		game->map[game->x][game->y] = '0';
		game->y--;
		game->map[game->x][game->y] = 'P';
	}
}
