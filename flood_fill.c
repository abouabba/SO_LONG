#include "so_long.h"

char **copy_map(char **map, int height)
{
	char **map_copy;
	int i;

	map_copy = malloc((height + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;

	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[height] = NULL;
	return (map_copy);
}



void	flood_fill(t_game *game, int x, int y)
{
	printf ("%c-----------\n", game->copy[x][y]);
	if (game->copy[x][y] == '1' || game->copy[x][y] == 'F')
		return ;

	game->copy[x][y] = 'F';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	check_valid_path(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				print_error("Error\n!In valid mappppp");
				return ;
			}
			j++;
		}
		i++;
	}
}
