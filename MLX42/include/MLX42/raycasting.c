/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:42:02 by alamizan          #+#    #+#             */
/*   Updated: 2023/08/08 17:37:30 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "MLX42.h"
# include <stdlib.h>
#include <math.h>
#include <stdio.h>

# define screenWidth 640
# define screenHeight 480
# define largeur 24
# define hauteur 24

//gcc tuto_mlx.c libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
int worldMap[largeur][hauteur]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	main(void)
{
	void	*mlx;
	void	*win;

	int	h;			// hauteur en pxel de lecran
	double	pos_x;	// position de departclang: error: linker command failed with exit code 1 (use -v to see invocation)

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

	int draw_start;
	int draw_end;

	int	color;

	int	x;
	int	w;

	h = screenHeight;
	pos_x = 22;
	pos_y = 12;
	dir_x = -1;
	dir_y = 0;
	plane_x = 0;
	plane_y = 0.66;
	time = 0;
	old_time = 0;
	x = 0;
	w = 60;
	hit = 0;

// ************************************************************ //

	mlx = mlx_init(640, 480, "MLX42", true);
	if (mlx == NULL)
		return (1) ;

	mlx_image_t* img = mlx_new_image(mlx, 620, 480);

	mlx_loop(mlx);
	// boucle de raycasting
	while(x < w)
	{
		double camera_x;
		double ray_dir_x;
		double ray_dir_y;
		// calcule la position et la direction du rayon.
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
		printf("ray_dir_y  %lf\n" , ray_dir_y);

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
			printf ("side_dist_y %lf map_y : %d pos_y %f\tdelta_dist_y : %lf\n ",side_dist_y,map_y, pos_y, delta_dist_y);
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
			printf ("side_dist_y %lf map_y : %d pos_y %f\tdelta_dist_y : %lf\n ",side_dist_y,map_y, pos_y, delta_dist_y);
		}
		printf("-------------------------------------------------------------\n");
		printf("aavant DDA side_dist_y :%lf delta_dist_y : %lf \n", side_dist_y, delta_dist_y);
		printf("-------------------------------------------------------------\n");
		// execute le DDA
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (worldMap[largeur-1][hauteur-1] > 0)
				hit = 1;
		}
		//Calculer la distance projetée dans la direction de la caméra 
		printf("side :%d\n", side);
		printf("side_dist_x :%lf delta_dist_x : %lf \n", side_dist_x, delta_dist_x);
		printf("side_dist_y :%lf delta_dist_y : %lf \n", side_dist_y, delta_dist_y);
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);

		// Calculer la hauteur de la ligne à dessiner à l'écran
		int line_heiht;
		//if (perp_wall_dist == 0)
		//	perp_wall_dist = 1;
		line_heiht = (int)(h / perp_wall_dist);
		printf("h : %d,\tperp_wall_dist : %lf\n", h, perp_wall_dist);
		
		printf("draw_end:%d\t line_heiht : %d\n",draw_end,line_heiht);
		// calcule le pixel le plus bas et le plus haut 
		// pour remplir la bande actuelle
		draw_start = -line_heiht / 2 + h / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_heiht / 2 + h / 2;
				printf("after draw_end:%d\t line_heiht : %d \t h : %d",draw_end, line_heiht, h);
		if (draw_end >= h)
			draw_end = h - 1;
		//printf("-------------draw_end:%d\n",draw_end);
		//choisissez la couleur du mur
		if (worldMap[map_x][map_y] == 1)
			color = 0x0000FFFF;
		if (worldMap[map_x][map_y] == 2)
			color = 0xFF0000FF;
		if (worldMap[map_x][map_y] == 3)
			color = 0xFF00FFFF;
		if (worldMap[map_x][map_y] == 4)
			color = 0xFF00FFFF;
		else 
			color = 0xFFFFFFFF;

		// change la luminosite au cote x ou y
		if (side == 1)
			color = color / 2;

		//dessine les pixels de la bande sous la forme d'une ligne verticale

		while(draw_start < draw_end )
			mlx_put_pixel(img, x, draw_start++, color);
		
		// command deplacement:
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

	mlx_image_to_window(mlx, img, pos_x, pos_y);
	//mlx_loop_hook(mlx, hook, mlx);
	mlx_terminate(mlx);
}

