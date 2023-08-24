#include "../../include/cub3d.h"

// Initialize texture variables //
t_texture	*init_texture(void)
{
	t_texture	*text;
	int			i;

	text = malloc(sizeof(t_texture));
	if (!text)
		exit (1);
	i = 0;
	while (i < 3)
	{
		text->f[i] = -42;
		text->c[i] = -42;
		i++;
	}
	text->nb_texture = 0;
	text->north = NULL;
	text->south = NULL;
	text->west = NULL;
	text->east = NULL;
	return (text);
}

t_map	*init_map(t_param *param)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		if (param->text)
			close_texture(param->text, 0);
		exit (1);
	}
	return (map);
}

t_param	*init_param(void)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
	{
		ft_putendl_fd("Error\nmalloc problem", 2);
		exit (1);
	}
	param->text = init_texture();
	param->map = init_map(param);
	return (param);
}

t_ray	*init_raycasting(t_param *param)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
	{
		ft_putendl_fd("Error\nmalloc problem", 2);
		close_texture(param->text, 0);
		close_strucmap(param->map);
		exit (1);
	}
	return (ray);
}
