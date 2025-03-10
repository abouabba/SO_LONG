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
    if (game->map[game->y - 1][game->x] != '1')
    {
        game->map[game->y][game->x] = '0';
        game->y--;
        game->map[game->y][game->x] = 'P';
    }
}

void move_right(t_game *game)
{
    if (game->map[game->y][game->x + 1] != '1')
    {
        game->map[game->y][game->x] = '0';
        game->x++;
        game->map[game->y][game->x] = 'P';
    }
}

void move_down(t_game *game)
{
    if (game->map[game->y + 1][game->x] != '1')
    {
        game->map[game->y][game->x] = '0';
        game->y++;
        game->map[game->y][game->x] = 'P';
    }
}

void move_left(t_game *game)
{
    if (game->map[game->y][game->x - 1] != '1')
    {
        game->map[game->y][game->x] = '0';
        game->x--;
        game->map[game->y][game->x] = 'P';
    }
}
