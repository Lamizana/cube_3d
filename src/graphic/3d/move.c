#include "../../../include/cub3d.h"

void	hook_3d(void *parameter)
{
	t_param	*param;
	t_cam	*cam;
	t_map	*map;
	double	next_x;
	double	next_y;
	double	old_dir_x;
	double	old_plan_x;


	param = parameter;
	cam = param->cam;
	map = param->map;
	raycasting(param);
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_W))
	{
		printf("haut\n");
		next_x = cam->px + cam->dir_x * MOVE_SPEED;
		next_y = cam->py + cam->dir_y * MOVE_SPEED;
		if (map->map[(int)next_x][(int)next_y] == 0)
		{
			cam->px = next_x;
			cam->py = next_y;
		}
	}
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_S))
	{
		printf("bas\n");
		next_x = cam->px - cam->dir_x * MOVE_SPEED;
		next_y = cam->py - cam->dir_y * MOVE_SPEED;
		if (map->map[(int)next_x][(int)next_y] == 0)
		{
			cam->px = next_x;
			cam->py = next_y;
		}
	}
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_D))
	{
		printf("droite\n");
		next_x = cam->px + cam->dir_y * MOVE_SPEED;
		next_y = cam->py + (-cam->dir_x) * MOVE_SPEED;
		if (map->map[(int)next_x][(int)next_y] == 0)
		{
			cam->px = next_x;
			cam->py = next_y;
		}
	}
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_A))
	{
		printf("gauche\n");
		next_x = cam->px + (-cam->dir_y) * MOVE_SPEED;
		next_y = cam->py + cam->dir_x * MOVE_SPEED;
		if (map->map[(int)next_x][(int)next_y] == 0)
		{
			cam->px = next_x;
			cam->py = next_y;
		}
	}
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_LEFT))
	{
		old_dir_x = cam->dir_x;
		cam->dir_x = cam->dir_x * cos(ROT_SPEED) - cam->dir_y * sin(ROT_SPEED);
		cam->dir_y = old_dir_x * sin(ROT_SPEED) + cam->dir_y * cos(ROT_SPEED);
		old_plan_x = cam->plane_x;
		cam->plane_x = cam->plane_x * cos(ROT_SPEED) - cam->plane_y * sin(ROT_SPEED);
		cam->plane_y = old_plan_x * sin(ROT_SPEED) + cam->plane_y * cos(ROT_SPEED);
	}
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_RIGHT))
	{
		old_dir_x = cam->dir_x;
		cam->dir_x = cam->dir_x * cos(-ROT_SPEED) - cam->dir_y * sin(-ROT_SPEED);
		cam->dir_y = old_dir_x * sin(-ROT_SPEED) + cam->dir_y * cos(-ROT_SPEED);
		old_plan_x = cam->plane_x;
		cam->plane_x = cam->plane_x * cos(-ROT_SPEED) - cam->plane_y * sin(-ROT_SPEED);
		cam->plane_y = old_plan_x * sin(-ROT_SPEED) + cam->plane_y * cos(-ROT_SPEED);
	}
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(param->graph->mlx);
}
