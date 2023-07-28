#include "../../include/cub3d.h"

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
			j++;
		}
		i++;
	}
	return (0);
}
