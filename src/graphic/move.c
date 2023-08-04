#include "../../include/cub3d.h"

void	cam_rot(t_cam cam)
{
	if (mmlx_is_key_down(graph->mlx, MLX_KEY_LEFT))
	{
		cam->pa += 0.1;
		if (pa > 2 * PI)
			pa -= 2 * PI;
		cam->dx = cos(pa) * 5;
		cam->dy = sin(PA) * 5;
	}

	if (mlx_is_key_down(graph->mlx, MLX_KEY_LEFT))
	{
		cam->pa-=0.1;
		if (pa < 0)
			pa += 2 * PI;
		cam->dx = cos(pa) * 5;
		cam->dy = sin(PA) * 5;
	}
}
void	move_minimap(t_graph *graph)
{

	if (mlx_is_key_down(graph->mlx, MLX_KEY_W))
		graph->img_p->instances[0].y -= 1;
	if (mlx_is_key_down(graph->mlx, MLX_KEY_D))
		graph->img_p->instances[0].y += 1;
	if (mlx_is_key_down(graph->mlx, MLX_KEY_A))
		graph->img_p->instances[0].x -= 1;
	if (mlx_is_key_down(graph->mlx, MLX_KEY_D))
		graph->img_p->instances[0].x += 1;

}
