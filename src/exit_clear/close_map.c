#include "../../include/cub3d.h"

void	close_strucmap(t_map *map)
{
	if (map->map)
		ft_freestrs(map->map);
	if (map->point)
		free(map->point);
	free(map);
}

void	close_texture(t_texture *text)
{
	int	i;

	i = 3;
	while (i < 9)
	{
		close(i);
		i++;
	}
	free(text);
}

void	close_map(t_texture *text, t_map *map)
{
	if (text)
		close_texture(text);
	if (map)
		close_strucmap(map);
	exit(1);
}
