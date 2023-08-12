/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:55:35 by alamizan          #+#    #+#             */
/*   Updated: 2023/08/12 12:02:45 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MLX42.h"
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480
#define MAP_WITDH		10
#define MAP_HEIGHT		10
//clang ray.c libmlx42.a -Iinclude -ldl -lglfw  -lm -g

int mappemonde[MAP_WITDH][MAP_HEIGHT]=
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
} ;

/* ************************************************************************** */
typedef struct s_ray
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	int		h;			// hauteur en pixel de lecran
	int		w;			// largeur en pixel de lecran
	int		index;		// nb de pixel dans la colonne a afficher
	double	pos_x;		// position x de depart
	double	pos_y;		// position y de depart

	double	camera_x;	// coordonnée x dans l'espace caméra
	double	ray_dir_x;
	double	ray_dir_y;
	double	dir_x;		// vecteur x direction joueur
	double	dir_y;		// vecteur y direction joueur

	double	old_dir_x;
	double	old_plan_x;

	double	plane_x;	// plan camera x du joueur
	double	plane_y; 	// plan camera y du joueur

	double	time;		// trame courante
	double	old_time;	// trame precedente

	double	side_dist_x;// longeur du rayon de la pos actuel au cote x ou y
	double	side_dist_y;
	double	perp_wall_dist;

	double	delta_dist_x;
	double	delta_dist_y;
	double	distance;
	int		step_x; 	// direction ou aller (x ou y)
	int		step_y;

	int		hit;	// mur touche
	int		side;	// mur NS ou EW touche

	int		map_x;	// emplacement x sur la carte
	int		map_y;	// emplacement y sur la carte

	int		line_height;// hauteur de la ligne vertical qui doit etre tracer
	int		draw_start; // depart y put_pixel
	int		draw_end;	// fin y put_pixel

	uint32_t color;		// colors en hexadecimal

	int		x;
}	t_ray;

/* ************************************************************************** */
int	init_data(t_ray *data)
{
	data->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "MLX42", true);
	if (data->mlx == NULL)
		return (1);
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (data->img == NULL)
		return (1);

	data->pos_x = 7;
	data->pos_y = 8;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->x = 0;
	data->h = SCREEN_HEIGHT;
	data->w = SCREEN_WIDTH;
	data->side_dist_x = 0;
	data->side_dist_y = 0;
	data->perp_wall_dist = 0;
	data->step_x = 0;
	data->step_y = 0;
	data->hit = 0;
	data->side = 0;
	data->line_height = 0;
	data->draw_start = 0;
	data->draw_end = 0;
	return (0);
}

/* ************************************************************************** */
// Calcule la hauteur de la ligne à dessiner à l'écran:
// calcule le pixel le plus bas et le plus haut pour remplir la bande actuelle
void	create_vertical_line(t_ray *data)
{
	data->draw_start = 0;
	data->draw_end = 0;
	data->index = 0;
	data->line_height = fabs(data->h / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + data->h / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + data->h / 2;
	if (data->draw_end >= data->h)
		data->draw_end = data->h - 1;

	printf("hauteur ligne: %d\t", data->line_height);
	printf("emplacement x: : %d\n", data->x);
	printf("draw start: %d\t", data->draw_start);
	printf("draw end: %d\n", data->draw_end);

	// ************************************************** //
	// if (data->line_height > data->h)
	// {
		// data->index = data->x;
		// data->draw_start = (data->line_height - data->h) / 2;
		// data->draw_end = data->draw_start + 1;
	// }
	// else
	// {
		// data->index = data->x + ((SCREEN_HEIGHT - data->line_height) / 2) * SCREEN_WIDTH;
		// data->draw_start = 0;
		// data->draw_end = 0;
	// }

}

/* ************************************************************************** */
// Dessine les pixels de la bande sous la forme d'une ligne verticale
void	vertical_line(t_ray *data)
{
	int	y;
// 
	// if (data->draw_end < data->draw_start)
	// {
		// data->draw_start += data->draw_end;
		// data->draw_end = data->draw_start - data->draw_end;
		// data->draw_start -= data->draw_end;
	// }
	// if (data->draw_end < 0 || data->draw_start >= data->h
		// || data->x < 0 || data->x >= data->w)
		// return ;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_end >= data->h)
		data->draw_end = data->h - 1;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		mlx_put_pixel(data->img, data->x, y, data->color);
		y++;
	}
}

/* ************************************************************************** */
void	raycasting(void *param)
{
	t_ray *data;

	data= param;
	data->x = 0;
	while (data->x < data->w)
	{
		// Position et direction du rayon:
		data->camera_x = 2 * data->x / (double)data->w - 1;
		data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
		data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;

		// Case de la carte ou nous sommme:
		data->map_x = (int)data->pos_x;
		data->map_y = (int)data->pos_y;

		// Longueur du rayon d'un côté x ou y au côté x ou y suivant
		data->delta_dist_x = sqrt(1 + (data->ray_dir_y * data->ray_dir_y)
				/ (data->ray_dir_x * data->ray_dir_x));
		data->delta_dist_y = sqrt(1 + (data->ray_dir_y * data->ray_dir_y)
				/ (data->ray_dir_x * data->ray_dir_x));

		// calcule l etape et la side__dist initial
		if (data->ray_dir_x < 0)
		{
			data->step_x = -1;
			data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
		}
		else
		{
			data->step_x = 1;
			data->side_dist_x = (data->map_x + 1.0 - data->pos_x) * data->delta_dist_x;
		}
		if (data->ray_dir_y < 0)
		{
			data->step_y = -1;
			data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
		}
		else
		{
			data->step_y = 1;
			data->side_dist_y = (data->map_y + 1.0 - data->pos_y) *data->delta_dist_y;
		}

		//passe au carré suivant de la carte, soit direction x, soit direction y
		while (data->hit == 0)
		{
			if (data->side_dist_x < data->side_dist_y)
			{
				data->side_dist_x += data->delta_dist_x;
				data->map_x += data->step_x;
				data->side = 0;
			}
			else
			{
				data->side_dist_y += data->delta_dist_y;
				data->map_y += data->step_y;
				data->side = 1;
			}
			// Vérifier si le rayon a touché un mur
			if (mappemonde[data->map_x][data->map_y] > 0)
				data->hit = 1;
		}

		// Calculer la distance projetée dans la direction de la caméra:
		if (data->side == 0)
			data->perp_wall_dist = fabs((data->map_x - data->ray_dir_x
						+ (1 - data->step_x) / 2) / data->ray_dir_x);
			// data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
		else
		//	data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
			data->perp_wall_dist = fabs((data->map_y - data->ray_dir_y
						+ (1 - data->step_y) / 2) / data->ray_dir_y);


		create_vertical_line(data);	
	
		// Couleur du mur:
		// if (mappemonde[data->map_x][data->map_y] == 1)
			data->color = 0x00FF00FF; //vert
		// else 
			// data->color = 0x000000FF; //noir
									  
		// Change la luminosite au cote x ou y
		// if (data->side == 1)
			// data->color = data->color / 2;

		vertical_line(data);
		data->x++;
	}
}

/* ************************************************************************** */
void	hook(void *param)
{
	t_ray	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		printf("haut\n");
		if (mappemonde[(int)(data->pos_x + data->dir_x * 5)][(int)data->pos_y] == false)
				data->pos_x += data->dir_x *5;
		if (mappemonde[(int)data->pos_x][(int)(data->pos_y + data->dir_y * 5)]  == false)
				data->pos_y += data->dir_y *5;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		printf("droite\n");
		data->old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos (-3) - data->dir_y * sin(-3);
		data->dir_y = data->old_dir_x * sin (-3) + data->dir_y * cos(-3);
		data->old_plan_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-3) - data->plane_y * sin(-3);
		data->plane_y = data->old_plan_x * sin(-3) + data->plane_y * cos(-3);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		printf("gauche\n");
		data->old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos (3) - data->dir_y * sin(3);
		data->dir_y = data->old_dir_x * sin (3) + data->dir_y * cos(3);
		data->old_plan_x = data->plane_x;
		data->plane_x = data->plane_x * cos(3) - data->plane_y * sin(3);
		data->plane_y = data->old_plan_x * sin(3) + data->plane_y * cos(3);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		printf("bas\n");
		if (mappemonde[(int)(data->pos_x - data->dir_x * 5)][(int)data->pos_y] == false)
			data->pos_x -= data->dir_x *5;
		if (mappemonde[(int)data->pos_x][(int)(data->pos_y - data->dir_y * 5)]  == false)
			data->pos_y -= data->dir_y *5;

	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}

/* ************************************************************************** */
int	main(void)
{
	t_ray	*data;

	data = malloc(sizeof(t_ray));
	if (init_data(data) == 1)
		return (EXIT_FAILURE);
	//raycasting(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop_hook(data->mlx, hook, data);
	mlx_loop_hook(data->mlx, raycasting, data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	free(data);
	return (0);
}
