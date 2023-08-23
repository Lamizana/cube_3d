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

typedef struct s_map
{
	int		fd_map;
	char	**map;
	int		len_m;
	int		index_m;
	int		pos_nb;
	char	pos_init;
}	t_map;

typedef struct s_graph
{
	mlx_t		*mlx;
	int			width;
	int			heigth;
	mlx_image_t	*img_1;
	mlx_image_t	*img_0;
	mlx_image_t	*img_p;
	mlx_image_t	*img_v;

	float	pa; // angle of the player
}	t_graph;

typedef struct s_camera
{
	double	px; // position x
	double	py; // position x
	double	dir_x; // direction x
	double	dir_y; // direction y
	double	pa; // angle of the player
	double	plane_x;
	double	plane_y;
	double	delta_x; // delta x
	double	delta_y; // delta y
}	t_cam;

typedef struct s_raycasting
{
	// int		r;
	int		mx;	// mapX
	int		my;	// mapY
	// int		mp;
	// int		depth_of_field;
	float	rx;
	float	ry;
	float	ra;
	// float	xo;
	// float	yo;
	float	tan_a;
	int	side;
	double	side_dist_x;
	double	side_dist_y;
	int		draw_start; // depart y put_pixel
	int		draw_end;	// fin y put_pixel
}	t_ray;

typedef struct s_param
{
	t_texture	*text;
	t_map		*map;
	t_graph		*graph;
	t_cam		*cam;
	t_ray		*ray;
}	t_param;

#endif
