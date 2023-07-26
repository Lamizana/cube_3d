#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_texture
{
	int	north;
	int	south;
	int	west;
	int	east;
	int	c[3];
	int	f[3];
}	t_texture;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	char	**map;
	char	pos_init;
}	t_map;
#endif
