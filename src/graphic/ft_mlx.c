#include "../../include/cub3d.h"

void find_player(t_param *param)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	// Recuperer la position du player:
	while (param->map->map[i] != NULL)
	{
		j = 0;
		while(param->map->map[i][j])
		{
			if (param->map->map[i][j] == param->map->pos_init)
			{
				param->ray->pos_x = (double)i;
				param->ray->pos_y = (double)j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	init_mlx(t_param *param)
{
	param->ray->mlx = mlx_init(WIDTH, HEIGHT, "CUBE 3D", true);
	if (param->ray->mlx == NULL)
		return (1);
	param->ray->img = mlx_new_image(param->ray->mlx, WIDTH, HEIGHT);
	if (param->ray->img == NULL)
		return (1);
	find_player(param);
	param->ray->dir_x = -1;
	param->ray->dir_y = 0;
	param->ray->plane_x = 0;
	param->ray->plane_y = 0.66;
	param->ray->h = HEIGHT;
	param->ray->w = WIDTH;
	return (0);
}
/* ************************************************************************** */
void	calcul_map(t_ray *ray)
{
	// Position et direction du rayon:
	ray->camera_x = 2 * ray->x / (double)ray->w - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;

	// Case de la carte ou nous sommme:
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;

	ray->side_dist_x = 0;
	ray->side_dist_y = 0;

	// Longueur du rayon d'un côté x ou y au côté x ou y suivant
	ray->delta_dist_x = sqrt(1 + (ray->ray_dir_y * ray->ray_dir_y)
				/ (ray->ray_dir_x * ray->ray_dir_x));
	ray->delta_dist_y = sqrt(1 + (ray->ray_dir_x * ray->ray_dir_x)
				/ (ray->ray_dir_y * ray->ray_dir_y));
}

/* ************************************************************************** */
// calcule l etape et la side__dist initial
void	calcul_step(t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) *ray->delta_dist_y;
	}
}

/* ************************************************************************** */
void	dda(t_ray *ray, t_map *map)
{
	// DDA
	//passe au carré suivant de la carte, soit direction x, soit direction y
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		// Vérifier si le rayon a touché un mur
		if (map->map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

/* ************************************************************************** */
// Calcule la hauteur de la ligne à dessiner à l'écran:
// calcule le pixel le plus bas et le plus haut pour remplir la bande actuelle
void	create_vertical_line(t_ray *ray)
{
	ray->line_height = (int)(ray->h / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + ray->h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + ray->h / 2;
	if (ray->draw_end >= ray->h)
		ray->draw_end = ray->h - 1;
}

/* ************************************************************************** */
// Choisi la couleur en fonction du mur:
void	color_choice(t_ray *ray, t_map *map)
{
	// Couleur du mur:
	if (map->map[ray->map_x][ray->map_y] == '1')
		ray->color = 0x00FF00FF; //vert
									
	//Change la luminosite au cote x ou y
	if (ray->side == 1)
		ray->color = ray->color / 2;
}

/* ************************************************************************** */
// Dessine les pixels de la bande sous la forme d'une ligne verticale
void	vertical_line(t_ray *ray)
{
	int	y;
	int ground;
	int ceilling;

	ground = 0;
	while (ground < ray->draw_start)
	{
		mlx_put_pixel(ray->img, ray->x, ground, 0xFF00000F);
		ground++;
	}
	y = ray->draw_start;
	while (y <=ray->draw_end)
	{
		mlx_put_pixel(ray->img, ray->x, y, ray->color);
		y++;
	}
	ceilling = ray->draw_end;
	while (ceilling  < ray->h)
	{
		mlx_put_pixel(ray->img, ray->x, ceilling, 0xF00FFFF);
		ceilling++;
	}

}

/* ************************************************************************** */
void	raycasting(t_param *parameter)
{
	t_param	*param;
	t_ray	*ray;
	t_map	*map;

	param = parameter;
	ray = param->ray;
	map = param->map;
	ray->x = 0;
	while (ray->x < ray->w)
	{
		calcul_map(ray);
		calcul_step(ray);
		dda(ray, map);

		// Calculer la distance projetée dans la direction de la caméra:
		if (ray->side == 0)
			ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
		else
			ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;

		create_vertical_line(ray);	
		color_choice(ray, map);
		vertical_line(ray);
		ray->x++;
	}
}

/* ************************************************************************** */
void	hook(void *parameter)
{
	t_param *param;
	t_ray	*ray;
	t_map	*map;
	double	rot_speed;
	double	move_speed;
	double	next_x;
	double	next_y;

	param = parameter;
	map = param->map;
	ray = param->ray;
	move_speed = 0.1;
	rot_speed = 0.03;
	raycasting(param);
	if (mlx_is_key_down(ray->mlx, MLX_KEY_W))
	{
		printf("haut\n");
		next_x = ray->pos_x + ray->dir_x * move_speed;
		next_y = ray->pos_y + ray->dir_y * move_speed;
		if ((map->map[(int)next_x][(int)next_y] == '0')
			|| (map->map[(int)next_x][(int)next_y] == map->pos_init))
		{
			ray->pos_x = next_x;
			ray->pos_y = next_y;
		}
	}
	if (mlx_is_key_down(ray->mlx, MLX_KEY_S))
	{
		printf("bas\n");
		next_x = ray->pos_x - ray->dir_x * move_speed;
		next_y = ray->pos_y - ray->dir_y * move_speed;
		if ((map->map[(int)next_x][(int)next_y] == '0')
			|| (map->map[(int)next_x][(int)next_y] == map->pos_init))
		{
			ray->pos_x = next_x;
			ray->pos_y = next_y;
		}
	}
	if (mlx_is_key_down(ray->mlx, MLX_KEY_D))
	{
		printf("droite\n");
		next_x = ray->pos_x + ray->dir_y * move_speed;
		next_y = ray->pos_y + (-ray->dir_x) * move_speed;
		if ((map->map[(int)next_x][(int)next_y] == '0')
			|| (map->map[(int)next_x][(int)next_y] == map->pos_init))
		{
			ray->pos_x = next_x;
			ray->pos_y = next_y;
		}
	}
	if (mlx_is_key_down(ray->mlx, MLX_KEY_A))
	{
		printf("gauche\n");
		next_x = ray->pos_x + (-ray->dir_y) * move_speed;
		next_y = ray->pos_y + ray->dir_x * move_speed;
		if ((map->map[(int)next_x][(int)next_y] == '0')
			|| (map->map[(int)next_x][(int)next_y] == map->pos_init))
		{
			ray->pos_x = next_x;
			ray->pos_y = next_y;
		}
	}
	if (mlx_is_key_down(ray->mlx, MLX_KEY_LEFT))
	{
		ray->old_dir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(rot_speed) - ray->dir_y * sin(rot_speed);
		ray->dir_y = ray->old_dir_x * sin(rot_speed) + ray->dir_y * cos(rot_speed);
		ray->old_plan_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(rot_speed) - ray->plane_y * sin(rot_speed);
		ray->plane_y = ray->old_plan_x * sin(rot_speed) + ray->plane_y * cos(rot_speed);
	}
	if (mlx_is_key_down(ray->mlx, MLX_KEY_RIGHT))
	{
		ray->old_dir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(-rot_speed) - ray->dir_y * sin(-rot_speed);
		ray->dir_y = ray->old_dir_x * sin(-rot_speed) + ray->dir_y * cos(-rot_speed);
		ray->old_plan_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(-rot_speed) - ray->plane_y * sin(-rot_speed);
		ray->plane_y = ray->old_plan_x * sin(-rot_speed) + ray->plane_y * cos(-rot_speed);
	}
	if (mlx_is_key_down(ray->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(ray->mlx);
}

int	ft_mlx(t_param *param)
{
	if (init_mlx(param))
		return (1);
	raycasting(param);
	mlx_image_to_window(param->ray->mlx, param->ray->img, 0, 0);
	mlx_loop_hook(param->ray->mlx, hook, param);
	mlx_loop(param->ray->mlx);
	mlx_terminate(param->ray->mlx);
	return (0);
}
