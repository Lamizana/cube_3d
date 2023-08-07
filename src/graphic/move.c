#include "../../include/cub3d.h"

void	cam_rot(t_graph *cam)
{
	if (mlx_is_key_down(cam->mlx, MLX_KEY_RIGHT))
	{
		cam->pa += 0.1;
		if (cam->pa > 2 * PI)
			cam->pa -= 2 * PI;
		cam->dx = cos(cam->pa) * 5;
		cam->dy = sin(cam->pa) * 5;
	}
	if (mlx_is_key_down(cam->mlx, MLX_KEY_LEFT))
	{
		cam->pa -= 0.1;
		if (cam->pa < 0)
			cam->pa += 2 * PI;
		cam->dx = cos(cam->pa) * 5;
		cam->dy = sin(cam->pa) * 5;
		printf("cos cam->dx %f\n", cam->dx);
		printf("acm->dy %f\n", cam->dy);

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
	cam_rot(graph);
}
