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
		close(i++);
	if (text->north != NULL)
		free(text->north);
	if (text->south != NULL)
		free(text->south);
	if (text->west != NULL)
		free(text->west);
	if (text->east != NULL)
		free(text->east);
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
