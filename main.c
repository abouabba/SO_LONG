/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabba <abouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:41:06 by abouabba          #+#    #+#             */
/*   Updated: 2025/02/17 21:52:43 by abouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	in_valid_ber_file(const char *file_name)
{
	int	len;

	if (!file_name)
		return (0);
	len = 0;
	while (file_name[len])
		len++;
	if (len < 4)
		return (0);
	return (file_name[len - 4] == '.' &&
			file_name[len - 3] == 'b' &&
			file_name[len - 2] == 'e' &&
			file_name[len - 1] == 'r');
}

int count_map_lines(const char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	height= 0;
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

char **store_map_to_2d_array(const char *file_name)
{
	int		fd;
	int		i;
	int		height;
	char	**map;
	char	*line;

	height = count_map_lines(file_name);
	i = 0;
	if (height <= 0)
		return (NULL);
	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strchr(line, '\n'))
			*ft_strchr(line, '\n') = '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int main (int ac, char **av)
{
	char	**map;
	int		i;
	int		height;
	int		width;

	i = 0;
	if (ac != 2)
		return (1);
	if (!in_valid_ber_file(av[1]))
	{
		print_error("Error : file_name is not valid");
		return (1);
	}
	map = store_map_to_2d_array(av[1]);
	if (!map)
		return (1);
	height = count_map_lines(av[1]);
	width = ft_strlen(map[0]);
	if (!is_map_valid_by_walls(map, height, width))
	{
		print_error("Error\n!map is not valid");
		free_map(map);
		return (1);
	}
	if (!is_map_rectangular(map))
	{
		print_error("Error\n!map is not rectangular");
		free_map(map);
		return(1);
	}
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}
