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

