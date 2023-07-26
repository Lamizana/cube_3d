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
	int		fd_map;
	char	**map;
	char	pos_init;
	t_point	*point;
}	t_map;

// typedef struct s_param
// {
	// int			fd_map;
	// t_texture	*text;
	// t_map		*map;
// } name;

#endif
