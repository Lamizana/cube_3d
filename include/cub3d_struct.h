#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "cub3d.h"

typedef struct s_texture
{
	int		nb_texture;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		c[3];
	int		f[3];
}	t_texture;

/* ************************************************************************** */
typedef struct s_map
{
	int		fd_map;
	char	**map;
	int		len_m;
	int		index_m;
	int		pos_nb;
	char	pos_init;
}	t_map;

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

	int		hit;		// mur touche
	int		side;		// mur NS ou EW touche

	int		map_x;		// emplacement x sur la carte
	int		map_y;		// emplacement y sur la carte

	int		line_height;// hauteur de la ligne vertical qui doit etre tracer
	int		draw_start; // depart y put_pixel
	int		draw_end;	// fin y put_pixel

	uint32_t color;		// colors en hexadecimal

	int		x;
}	t_ray;

/* ************************************************************************** */
typedef struct s_param
{
	t_texture	*text;
	t_map		*map;
	t_ray		*ray;
}	t_param;
#endif
