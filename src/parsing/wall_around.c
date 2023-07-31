#include "../../include/cub3d.h"

int	check_arround( t_map *map, int i, int j, int index_max)
{
	int	sizeless;
	int	sizeplus;

	sizeless = 0;
	sizeplus = 0;
	if (i > 0)
		sizeless = ft_strlen(map->map[i - 1]);
	if (i < index_max)
		sizeplus = ft_strlen(map->map[i + 1]);
	// if (!map->map[i - 1][j] || !map->map[i][j - 1]
		// || !map->map[i + 1][j] || !map->map[i][j + 1])
		// return (1);
	if ((j < sizeless && (map->map[i - 1][j] == '1'
		|| map->map[i - 1][j] == '0' || map->map[i - 1][j] == map->pos_init)) 
		&& (j < sizeplus && (map->map[i + 1][j] == '1'
		|| map->map[i + 1][j] == '0' || map->map[i + 1][j] == map->pos_init))
		&& (map->map[i][j - 1] == '1' || map->map[i][j + 1] == '1'
		|| map->map[i][j - 1] == '0' || map->map[i][j + 1] == '0'
		|| map->map[i][j - 1] == map->pos_init
		|| map->map[i][j + 1] == map->pos_init))
		return (0);
	return (1);
}

int	wall_around_map(t_map *map, int index_max)
{
	int	i;
	int	j;
	int	size_line;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		size_line = ft_strlen(map->map[i]);
		while (map->map[i][j])
		{
			if ((i == 0 || i == (index_max - 1))
				&& (map->map[i][j] == '0' || map->map[i][j] == map->pos_init))
			{
				printf("wrong map\n");
				return (1);
			}
			if ((j == 0 || j == (size_line - 1))
				&& (map->map[i][j] == '0' || map->map[i][j] == map->pos_init))
			{
				printf("wrong map\n");
				return (1);
			}
			if (map->map[i][j] == '0' || map->map[i][j] == map->pos_init)
			{
				if (check_arround(map, i, j, index_max))
				{
					ft_putendl_fd("Error\nYour map is not close", 2);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
