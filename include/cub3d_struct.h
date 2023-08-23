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

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}	t_point;

typedef struct s_map
{
	int		fd_map;
	char	**map;
	int		len_m;
	int		index_m;
	int		pos_nb;
	char	pos_init;
	t_point	*point;
}	t_map;

typedef struct s_graph
{
	mlx_t		*mlx;
	mlx_image_t	*img_1;
	mlx_image_t	*img_0;
	mlx_image_t	*img_p;
	mlx_image_t	*img_v;
}	t_graph;

typedef struct s_camera
{
	float	fov;
	float	px;	// position x
	float	py;	// position x
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	dx;	// direction x
	float	dy;	// direction y
	float	pa;	// angle of the player
	double	plane_x;
	double	plane_y;
}	t_cam;

typedef struct s_raycasting
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		depth_of_field;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	tan_a;
}	t_ray;

typedef struct s_param
{
	t_texture	*text;
	t_map		*map;
	t_graph		*graph;
	t_cam		*cam;
}	t_param;

#endif
