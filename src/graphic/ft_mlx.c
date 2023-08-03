#include "../../include/cub3d.h"

void	hook(void *parameter)
{
	t_param		*param;
	uint32_t	x;
	uint32_t	y;

	param = parameter;
	// creation image pour les 1:
	for (x = 0; x < param->graph->img_1->width; x++)
		for (y= 0; y <param->graph->img_1->height; y++)
			mlx_put_pixel(param->graph->img_1, x , y , 0x0000FFFF);

	// creation image pour les 0:
	for (x = 0; x < param->graph->img_0->width; x++)
		for(y= 0; y < param->graph->img_0->height; y++)
			mlx_put_pixel(param->graph->img_0, x , y ,0x00FF0000);

	// creation image pour la position du perso:
	for (x = 0; x < param->graph->img_p->width; x++)
		for(y= 0; y < param->graph->img_p->height; y++)
			mlx_put_pixel(param->graph->img_p, x, y, rand() % RAND_MAX);
	// deplace le perso:
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_UP))
		param->graph->img_p->instances[0].y -= 5;
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_DOWN))
		param->graph->img_p->instances[0].y += 5;
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_LEFT))
		param->graph->img_p->instances[0].x -= 5;
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_RIGHT))
		param->graph->img_p->instances[0].x += 5;

	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_ESCAPE))
		 mlx_close_window(param->graph->mlx);
}

int	display_image(t_map *map, t_graph *graph)
{
	int	line;
	int	raw;
	int	x;
	int	y;

	x = 0;
	y = 0;
	line = 0;
	while (map->map[line] && line < map->index_m)
	{
		raw = 0;
		while (map->map[line][raw] && raw < map->len_m)
		{
			if (map->map[line][raw] == '1' || map->map[line][raw] == ' ')
			{
				if (mlx_image_to_window(graph->mlx, graph->img_1, x, y) < 0)
					return (1);
				x += 32;
			}
			else if (map->map[line][raw] == '0')
			{
				if (mlx_image_to_window(graph->mlx, graph->img_0, x, y) < 0)
					return (1);
				x += 32;
			}
			else if (map->map[line][raw] == map->pos_init)
			{
				if (mlx_image_to_window(graph->mlx, graph->img_p, x, y) < 0)
					return (1);
				x += 32;
			}
			if (map->map[line][raw + 1] == '\0')
			{
				x = 0;
				y += 32;
			}
			raw++;
		}
		line++;
	}
	return (0);
}

int	ft_mlx(t_map *map, t_texture *text)
{
	t_param	*param;

	for(int i = 0; i < map->index_m; i++)
		printf("----%s-----\n", map->map[i]);
	param = init_param(map, text);
	param->graph->mlx = mlx_init(map->index_m * BLOCK, \
			map->len_m * BLOCK, "Cub3D", true);
	if (!param->graph->mlx)
		return (1);
	param->graph->img_0 = mlx_new_image(param->graph->mlx, BLOCK, BLOCK);
	param->graph->img_1 = mlx_new_image(param->graph->mlx, BLOCK, BLOCK);
	if (!param->graph->img_1 || !param->graph->img_0)
		return (1);
	param->graph->img_p = mlx_new_image(param->graph->mlx, 8, 8);
	if (display_image(map, param->graph))
		return (1);
	mlx_loop_hook(param->graph->mlx, hook, param);
	mlx_loop(param->graph->mlx);
	mlx_terminate(param->graph->mlx);
	return (0);
}
