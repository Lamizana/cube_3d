#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "cub3d.h"

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		north_fd;
	int		south_fd;
	int		west_fd;
	int		east_fd;
	int		c[3];
	int		f[3];
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
	int		pos_nb;
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
