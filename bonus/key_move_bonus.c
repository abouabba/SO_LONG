/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:01:15 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/15 14:39:41 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_game *game)
{
	if (game->map[game->x - 1][game->y] != '1')
	{
		if (game->map[game->x - 1][game->y] == 'C')
			game->c_count--;
		if (game->map[game->x - 1][game->y] == 'E' && game->c_count != 0)
			return ;
		if (game->map[game->x - 1][game->y] == 'E' && game->c_count == 0)
			ft_exit(game);
		game->map[game->x][game->y] = '0';
		game->x--;
		game->map[game->x][game->y] = 'P';
		game->move++;
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->x][game->y + 1] != '1')
	{
		if (game->map[game->x][game->y + 1] == 'C')
			game->c_count--;
		if (game->map[game->x][game->y + 1] == 'E' && game->c_count != 0)
			return ;
		if (game->map[game->x][game->y + 1] == 'E' && game->c_count == 0)
			ft_exit(game);
		game->map[game->x][game->y] = '0';
		game->y++;
		game->map[game->x][game->y] = 'P';
		game->move++;
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->x + 1][game->y] != '1')
	{
		if (game->map[game->x + 1][game->y] == 'C')
			game->c_count--;
		if (game->map[game->x + 1][game->y] == 'E' && game->c_count != 0)
			return ;
		if (game->map[game->x + 1][game->y] == 'E' && game->c_count == 0)
			ft_exit(game);
		game->map[game->x][game->y] = '0';
		game->x++;
		game->map[game->x][game->y] = 'P';
		game->move++;
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->x][game->y - 1] != '1')
	{
		if (game->map[game->x][game->y - 1] == 'C')
			game->c_count--;
		if (game->map[game->x][game->y - 1] == 'E' && game->c_count != 0)
			return ;
		if (game->map[game->x][game->y - 1] == 'E' && game->c_count == 0)
			ft_exit(game);
		game->map[game->x][game->y] = '0';
		game->y--;
		game->map[game->x][game->y] = 'P';
		game->move++;
	}
}
