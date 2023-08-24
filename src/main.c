#include "../include/cub3d.h"

int check_argc(int argc)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error\nPrecise your map, please", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	*param;

	if (check_argc(argc) == 1)
		return (1);

	param = init_param();
	if (parsing(argv[1], param) == 1)
		close_map(param);
	param->ray = init_raycasting(param);
	// int	i;
	// i = 0;
	// while(param->map->map[i] != NULL)
		// printf("%s\n", param->map->map[i++]);
	ft_mlx(param);
	close_parameter(param);
	return (0);
}
