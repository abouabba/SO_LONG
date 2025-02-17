/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:05:07 by abouabba          #+#    #+#             */
/*   Updated: 2025/02/17 19:58:26 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include "../so_long/get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct so_long
{
	char **map;
}				so_long;

int		count_map_lines(const char *file_name);
char	**store_map_to_2d_array(const char *file_name);
int		in_valid_ber_file(const char *file_name);
void	free_map(char **map);
int		is_map_valid_by_walls(char **map, int height, int width);
void	print_error(char *msg);

#endif