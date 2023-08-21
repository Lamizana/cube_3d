/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:42:02 by alamizan          #+#    #+#             */
/*   Updated: 2023/08/09 14:12:09 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "MLX42.h"
#include <stdint.h>
# include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <sys/types.h>

# define screenWidth 640
# define screenHeight 480
# define largeur 24
# define hauteur 24

static	mlx_image_t	*img;
//gcc tuto_mlx.c libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
int worldMap[largeur][hauteur]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,2,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,3,3,3,3,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,1,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	hook(void* param)
{
	mlx_t* mlx;
	int	h;			// hauteur en pxel de lecran
	double	pos_x;	// position de depart
	double	pos_y;

	double	dir_x;	// vecteur direction joueur
	double	dir_y;

	double	old_dir_x;
	double	old_plan_x;

	double	plane_x;
	double	plane_y; //plan camera du joueur

	double	time;		// trame courante
	double	old_time;	// trame precedente

	double	side_dist_x;	// longeur du rayon de la pos actuel au cote x ou y
	double	side_dist_y;
	double	perp_wall_dist;

	double	delta_dist_x;
	double	delta_dist_y;

	int		step_x; // direction ou aller (x ou y)
	int		step_y;

	int	hit;	// mur touche
	int	side;	// mur NS ou EW touche

	int	map_x;	// emplacement sur la carte
	int	map_y;	

	int draw_start = 0;
	int draw_end = 0;

	uint32_t color;

	int	x;
	int	w;

	//h = screenHeight;
	h = screenHeight;
	pos_x = 3;
	pos_y = 4;
	dir_x = -1;
	dir_y = 0,
	plane_x = 0;
	plane_y = 0.66;
	time = 0;
	old_time = 0;
	x = 0;
	w = 640;
	hit = 0;


	mlx = param;
	while(x < w)
	{
		double camera_x;
		double ray_dir_x;
		double ray_dir_y;
draw_start = 0;
printf("-------------------------------------------------------------\n");
				printf("x = %d\n", x);
				printf("-------------------------------------------------------------\n");
		//calcule la position et la direction du rayon.
		camera_x = 2 * x / (double)w - 1;
		ray_dir_x = dir_x + plane_x * camera_x;
		ray_dir_y = dir_y + plane_y * camera_x;

		// case de la carte ou nous sommme
		map_x = (int)pos_x;
		map_y = (int)pos_y;
 
		// longueur du rayon d'un côté x ou y au côté x ou y suivant
		if (ray_dir_x == 0)
			delta_dist_x= 1e30;
		else
			delta_dist_x = fabs(1 / ray_dir_x);
		if (ray_dir_y == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = fabs(1 / ray_dir_y);

		// calcule le pas et la side__dist initial
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
		}
	/*		printf("-------------------------------------------------------------\n");
		printf("aavant DDA side_dist_y :%lf delta_dist_y : %lf \n", side_dist_y, delta_dist_y);
		printf("-------------------------------------------------------------\n");*/

		// execute le DDA
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{

				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (worldMap[map_x][map_y] > 0)
			{
			
				hit = 1;
			}
		}
//		Calculer la distance projetée dans la direction de la caméra 
		if (side == 0)
			perp_wall_dist = side_dist_x - delta_dist_x;
		else
			perp_wall_dist = side_dist_y - delta_dist_y;

		// Calculer la hauteur de la ligne à dessiner à l'écran
		int line_heiht;
		line_heiht = (int)(h / perp_wall_dist);
		/*printf("h : %d,\tperp_wall_dist : %lf\n", h, perp_wall_dist);
		
		printf("draw_end:%d\t line_heiht : %d\n",draw_end,line_heiht);*/
		// calcule le pixel le plus bas et le plus haut 
		//pour remplir la bande actuelle
		draw_start = -line_heiht / 2 + h / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_heiht / 2 + h / 2;
		if (draw_end >= h)
			draw_end = h - 1;
		
		
		// choisissez la couleur du mur
		if (worldMap[map_x][map_y] == 1)
		{
			color = 0x000000FF;
		}
		else if (worldMap[map_x][map_y] == 2)
		{
			color = 0xFF0000FF;
		}
		else if (worldMap[map_x][map_y] == 3)
			color = 0xFF00FFFF;
		else if (worldMap[map_x][map_y] == 4)
			color = 0x00FF00FF; 
		else 
			color = 0xFFFFFFFF; //blanc

//		change la luminosite au cote x ou y
		if (side == 1)
			color = color / 2;

		
		/*int tmp;
		if (draw_start > draw_end )
		{
			tmp = draw_start;
			draw_start = draw_end;
			if (draw_start < 0)
				draw_start *= -1;
			draw_end = tmp;
		}printf("draw_start : %d  draw_end :%d\n", draw_start, draw_end);*/
//		dessine les pixels de la bande sous la forme d'une ligne verticale
			while(draw_start < draw_end )
			{
				printf("x : %d", x);
				mlx_put_pixel(img, x, draw_start++, color);
				//z++
			}
	

//		command deplacement:
		if (mlx_is_key_down(mlx, MLX_KEY_W))
		{
			if (worldMap[(int)(pos_x + dir_x * 5)][(int)pos_y] == false)
				pos_x += dir_x *5;
			if (worldMap[(int)pos_x][(int)(pos_y + dir_y * 5)]  == false)
				pos_y += dir_y *5;
		}
		if (mlx_is_key_down(mlx, MLX_KEY_D))
		{
			old_dir_x = dir_x;
			dir_x = dir_x * cos (-3) - dir_y * sin(-3);
			dir_y = old_dir_x * sin (-3) + dir_y * cos(-3);
			old_plan_x = plane_x;
			plane_x = plane_x * cos(-3) - plane_y * sin(-3);
			plane_y = old_plan_x * sin(-3) + plane_y * cos(-3);
		}
		if (mlx_is_key_down(mlx, MLX_KEY_A))
		{

			old_dir_x = dir_x;
			dir_x = dir_x * cos (3) - dir_y * sin(3);
			dir_y = old_dir_x * sin (3) + dir_y * cos(3);
			old_plan_x = plane_x;
			plane_x = plane_x * cos(3) - plane_y * sin(3);
			plane_y = old_plan_x * sin(3) + plane_y * cos(3);

		}
		if (mlx_is_key_down(mlx, MLX_KEY_S))
		{
			if (worldMap[(int)(pos_x - dir_x * 5)][(int)pos_y] == false)
				pos_x -= dir_x *5;
			if (worldMap[(int)pos_x][(int)(pos_y - dir_y * 5)]  == false)
				pos_y -= dir_y *5;

		}

		x++;
	}

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

// ************************************************************ //
int	main(void)
{
	void	*mlx;

	mlx = mlx_init(640, 480, "MLX42", true);
	if (mlx == NULL)
		return (1) ;

	img = mlx_new_image(mlx, 640, 480);
	mlx_loop_hook(mlx, hook, mlx);
	mlx_image_to_window(mlx, img, 0	, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
