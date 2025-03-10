/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:05:07 by abouabba          #+#    #+#             */
/*   Updated: 2025/03/10 12:11:33 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
// # include "mlx/mlx_int.h"

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*wall;
	void		*empty;
	void		*player;
	void		*collectible;
	void		*exit;
	void		*right;
	void		*left;
	char		**copy;
	char		**map;
	int			width;
	int			height;
	int 		x;
	int 		y;
	int			c_count;
	int			P_count;
	int			e_count;
}				t_game;

int		count_map_lines(char *file_name);
char	**store_map_to_2d_array(char *file_name, int height);
int		in_valid_ber_file(char *file_name);
void	free_map(char **map);
int		is_map_valid_by_walls(char **map, int height, int width);
void	print_error(char *msg);
int		is_map_rectangular(char **map);
int		is_map_valid_chars(t_game *game);
char	**copy_map(char **map, int height);
void	flood_fill(t_game *game, int x, int y);
void	check_valid_path(t_game *game);
void	position_player(t_game *game);
void	init_game(t_game *game);
void	load_textures(t_game *game);
void	render_map(t_game *game);
int   handle_keypress(int keycode, t_game *game);
void check_valide(char **av, t_game *game);
void move_up(t_game *game);
void move_right(t_game *game);
void move_down(t_game *game);
void move_left(t_game *game);

#endif