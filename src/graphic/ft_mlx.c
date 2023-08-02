#include "../../include/cub3d.h"

void	ft_mlx(t_map *map, t_texture *text)
{
	t_param	*param;

	param = init_param(map, text);
	param->graph->mlx = mlx_init(map->index_m * BLOCK, map->len_m * BLOCK, "Cub3D", true);
	if (!param->graph->mlx)
		return (1);
	param->graph->img_0 = mlx_new_image(param->graph->mlx, BLOCK, BLOCK);
	param->graph->img_1 = mlx_new_image(param->graph->mlx, BLOCK, BLOCK);
	if (!map->img_1 || !map->img_0)
		return (1);
	//creation du perso:
	param->graph->img_p = mlx_new_image(param->graph->mlx, 8, 8);

	//affichage:
	display_image(param);

	mlx_loop_hook(param->graph->mlx, hook, param);
	mlx_loop(param->graph->mlx);
	mlx_terminate(param->graph->mlx);
	return (0);
}
