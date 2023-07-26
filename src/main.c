#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_texture	*texture;
	t_map		*map;

	texture = NULL;
	map = NULL;
	if (argc != 2)
	{
		ft_putendl_fd("Error\nPrecise your map, please", 2);
		return (1);
	}
	if (parsing(argv[1], texture, map) == 1)
		return (1);
	return (0);
}
