#include "../../include/cub3d.h"

t_graph	*init_graph(t_param *param)
{
	t_graph	*graph;

	graph = malloc(sizeof(t_graph));
	if (!graph)
	{
		ft_putendl_fd("Error\nmalloc problem", 2);
		close_param(param);
	}
	return (graph);
}

t_param	*init_param(t_map *map, t_texture *texture)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
	{
		ft_putendl_fd("Error\nmalloc problem", 2);
		close_map(texture, map);
	}
	param->text = texture;
	param->map = map;
	param->graph = init_graph(param);
	return (param);
}
