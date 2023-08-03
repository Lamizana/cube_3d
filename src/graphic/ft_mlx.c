#include "../../include/cub3d.h"

unsigned long createRGBA(int r, int g, int b, int a)
{   
    return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8)
           + (a & 0xff);
}

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
			mlx_put_pixel(param->graph->img_0, x , y, createRGBA(param->text->f[0], param->text->f[1], param->text->f[2], 255));
	// creation image pour la position du perso:
	for (x = 0; x < param->graph->img_p->width; x++)
		for(y= 0; y < param->graph->img_p->height; y++)
			mlx_put_pixel(param->graph->img_p, x, y, rand() % RAND_MAX);
	move_minimap(param->graph);
	if (mlx_is_key_down(param->graph->mlx, MLX_KEY_ESCAPE))
		 mlx_close_window(param->graph->mlx);
}

static void	minimap_newline(int *x, int *y, char map, int *raw)
{
	*x += 32;
	if (map == '\0')
	{
		*x = 0;
		*y += 32;
	}
	*raw = *raw + 1;
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
			if (map->map[line][raw] == '1')
				if (mlx_image_to_window(graph->mlx, graph->img_1, x, y) < 0)
					return (1);
			if (map->map[line][raw] == '0'
				|| map->map[line][raw] == map->pos_init)
				if (mlx_image_to_window(graph->mlx, graph->img_0, x, y) < 0)
					return (1);
			minimap_newline(&x, &y, map->map[line][raw + 1], &raw);
		}
		line++;
	}
	return (0);
}

int	display_perso(t_map *map, t_graph *graph)
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
			if (map->map[line][raw] == map->pos_init)
				if (mlx_image_to_window(graph->mlx, graph->img_p, x, y) < 0)
					return (1);
			minimap_newline(&x, &y, map->map[line][raw + 1], &raw);
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
	param->graph->mlx = mlx_init(map->len_m * BLOCK, \
			map->index_m * BLOCK, "Cub3D", true);
	if (!param->graph->mlx)
		return (1);
	param->graph->img_0 = mlx_new_image(param->graph->mlx, BLOCK, BLOCK);
	param->graph->img_1 = mlx_new_image(param->graph->mlx, BLOCK, BLOCK);
	if (!param->graph->img_1 || !param->graph->img_0)
		return (1);
	param->graph->img_p = mlx_new_image(param->graph->mlx, 8, 8);
	if (display_image(map, param->graph) || display_perso(map, param->graph))
		return (1);
	mlx_loop_hook(param->graph->mlx, hook, param);
	mlx_loop(param->graph->mlx);
	mlx_terminate(param->graph->mlx);
	return (0);
}
