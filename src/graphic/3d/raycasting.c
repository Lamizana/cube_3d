#include "../../../include/cub3d.h"

/* ************************************************************************** */
// Calcule la hauteur de la ligne à dessiner à l'écran:
// calcule le pixel le plus bas et le plus haut pour remplir la bande actuelle
void	create_vertical_line(t_ray *ray, double perp_wall_dist)
{
	int line_height;
	float	draw_start;
	
	line_height = (int)(HEIGHT / perp_wall_dist);
	ray->draw_start = -line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

/* ************************************************************************** */
// Choisi la couleur en fonction du mur:
void	color_choice(t_ray *data)
{
	// Couleur du mur:
	if (map->map[data->map_x][data->map_y] == 1)
		data->color = 0x00FF00FF; //vert
	if (map->map[data->map_x][data->map_y] == 2)
		data->color = 0x000000FF; //noir
	if (map->map[data->map_x][data->map_y] == 3)
		data->color = 0x00f000FF; // gris
									
	//Change la luminosite au cote x ou y
	if (data->side= = 1)
		data->color = data->color / 2;
}

/* ************************************************************************** */
// Dessine les pixels de la bande sous la forme d'une ligne verticale
void	vertical_line(t_ray *data)
{
	int	y;
	int ground;
	int ceilling;

	ground = 0;
	while (ground < data->draw_start)
	{
		mlx_put_pixel(data->img, data->x, ground, 0xFF00000F);
		ground++;
	}
	y = data->draw_start;
	while (y <=data->draw_end)
	{
		mlx_put_pixel(data->img, data->x, y, data->color);
		y++;
	}
	ceilling = data->draw_end;
	while (ceilling  < HEIGHT)
	{
		mlx_put_pixel(data->img, data->x, ceilling, 0xF00FFFF);
		ceilling++;
	}

}

/* ************************************************************************** */

void	raycasting(void *parameter)
{
	t_param	*param;
	int		x;
	double	perp_wall_dist;
	
	param = parameter;
	x = 0;
	while (x < WIDTH)
	{
		calcul_map(param);
		calcul_step(param);
		dda(param);

		// Calculer la distance projetée dans la direction de la caméra:
		if (param->ray->side == 0)
			perp_wall_dist = param->ray->side_dist_x - param->cam->delta_x;
		else
			perp_wall_dist = param->ray->side_dist_y - param->cam->delta_y;

		create_vertical_line(param, perp_wall_dist);	
		color_choice(param);
		vertical_line(param);
		x++;
	}
}
