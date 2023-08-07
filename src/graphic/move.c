#include "../../include/cub3d.h"

void	cam_rot(t_graph *graph)
{
	if (mlx_is_key_down(graph->mlx, MLX_KEY_RIGHT))
	{
		graph->pa += 0.1;
		if (graph->pa > 2 * PI)
		{
			graph->pa -= 2 * PI;
		}
		graph->img_v->instances[0].x = (cos(graph->pa) * 10) + graph->img_p->instances[0].x + (SIZE_P / 2 - SIZE_V / 2);// + graph->img_p->width/2;
		graph->img_v->instances[0].y = (sin(graph->pa) * 10) + graph->img_p->instances[0].y+  (SIZE_P / 2 - SIZE_V / 2);// + graph->img_p->height/2;

	}
	if (mlx_is_key_down(graph->mlx, MLX_KEY_LEFT))
	{
		graph->pa -= 0.1;
		if (graph->pa < 0)
		{
			graph->pa += 2 * PI;
		}
		graph->img_v->instances[0].x = (cos(graph->pa) * 10) + graph->img_p->instances[0].x + (SIZE_P/ 2 - SIZE_V / 2);// + graph->img_p->width/2;
		graph->img_v->instances[0].y = (sin(graph->pa) * 10) + graph->img_p->instances[0].y +(SIZE_P / 2 - SIZE_V / 2);// + graph->img_p->height/2;
	}
	// if (mlx_is_key_down(graph->mlx, MLX_KEY_UP))
	// {
		// graph->img_v->instances[0].x += (cos(graph->pa) * 10);
		// graph->img_v->instances[0].y += (sin(graph->pa) * 10);
	// }
	// else if (mlx_is_key_down(graph->mlx, MLX_KEY_DOWN))
	// {
		// graph->img_v->instances[0].x -= (cos(graph->pa) * 10);
		// graph->img_v->instances[0].y -= (sin(graph->pa) * 10); 
	// }
// 
}

void	move_minimap(t_graph *graph)
{
	if (mlx_is_key_down(graph->mlx, MLX_KEY_W))
	{
		graph->img_p->instances[0].y -= 1;
		graph->img_v->instances[0].y -= 1;
	}
	if (mlx_is_key_down(graph->mlx, MLX_KEY_D))
	{
		graph->img_p->instances[0].x += 1;
		graph->img_v->instances[0].x += 1;
	}
	if (mlx_is_key_down(graph->mlx, MLX_KEY_A))
	{
		graph->img_p->instances[0].x -= 1;
		graph->img_v->instances[0].x -= 1;
	}
	if (mlx_is_key_down(graph->mlx, MLX_KEY_S))
	{
		graph->img_p->instances[0].y += 1;
		graph->img_v->instances[0].y += 1;
	}
	cam_rot(graph);
}
