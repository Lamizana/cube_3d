#include "../../include/cub3d.h"

void	move_minimap(t_graph *graph)
{
	if (mlx_is_key_down(graph->mlx, MLX_KEY_UP))
		graph->img_p->instances[0].y -= 5;
	if (mlx_is_key_down(graph->mlx, MLX_KEY_DOWN))
		graph->img_p->instances[0].y += 5;
	if (mlx_is_key_down(graph->mlx, MLX_KEY_LEFT))
		graph->img_p->instances[0].x -= 5;
	if (mlx_is_key_down(graph->mlx, MLX_KEY_RIGHT))
		graph->img_p->instances[0].x += 5;
}
