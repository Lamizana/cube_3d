#include "../../include/cub3d.h"

void	rays_draw(t_graph *graph, t_map *map)
{
	t_ray	*ray;

	ray->ra = graph->pa;
	ray->r = 0;
	while (r < 1)
	{
		ray->depth_of_field = 0;
		ray->r++;
		if (ray->ra > PI)
		{
			ray->ry = ((int)ray->py>>6)<<6)-0.0001;
			ray->rx = (ray->py - ray->ry) * ray->tan_a + graph->img_p->instances[0].x;
			ray->yo = -64;
			ray->xo = -ray->yo * ray->tan_a;
		}
		else if (ray->ra < PI)
		{
			ray->ry = ((int)ray->py>>6)<<6) + 64;
			ray->rx = (ray->py - ray->ry) * ray->tan_a + graph->img_p->instances[0].x;
			ray->yo = 64;
			ray->xo = -ray->yo * ray->tan_a;
		}
		else if (ray->ra == 0 || ray->ra == M_PI)
		{
			ray->rx = graph->img_p->instances[0].x;
			ray->ry = graph->img_p->instances[0].y;
			ray->depth_of_field = 8;
		}
		while (ray->depth_of_field < 8)
		{
			ray->mx = (int)ray->rx>>6;
			ray->my = (int)ray->rx>>6;
			ray->mp = ray->my * map->len_m + ray->mx;
			if (ray->mp < map->index_m * map->len_m && map->map[ray->mx][ray->my])
				ray->depth_of_field = 8;
		}
	}
}
