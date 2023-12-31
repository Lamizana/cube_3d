#include "../include/cub3d.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_texture	*texture;
	t_map		*map;

	texture = malloc (sizeof(t_texture));
	init_texture(texture);
	map = ft_calloc(1, sizeof(t_map));
	if (argc != 2)
	{
		ft_putendl_fd("Error\nPrecise your map, please", 2);
		close_map(texture, map);
	}
	if (parsing(argv[1], texture, map) == 1)
		close_map(texture, map);
	ft_mlx(map, texture);
	close_strucmap(map);
	close_texture(texture, 0);
	return (0);
}
