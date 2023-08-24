#include "../../include/cub3d.h"

void	close_strucmap(t_map *map)
{
	if (map->map)
		ft_freestrs(map->map);
	free(map);
}

void	close_texture(t_texture *text, int flag)
{
	int	i;

	if (text->north != NULL)
		free(text->north);
	if (text->south != NULL)
		free(text->south);
	if (text->west != NULL)
		free(text->west);
	if (text->east != NULL)
		free(text->east);
	if (flag == 0)
	{
		i = 3;
		while (i < 9)
			close(i++);
		free(text);
	}
	else if (flag == 1)
	{
		text->north = NULL;
		text->south = NULL;
		text->west = NULL;
		text->east = NULL;
	}
}

void	close_map(t_param *param)
{
	if (param->text)
		close_texture(param->text, 0);
	if (param->map)
		close_strucmap(param->map);
	free(param);
	exit(1);
}

void	close_parameter(t_param *param)
{
	if (param)
	{
		close_strucmap(param->map);
		close_texture(param->text, 0);
		// close_raycasting(param);
		free(param);
	}
	exit(1);
}
