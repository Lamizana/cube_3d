#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_texture	*texture;
	t_map		*map;


	texture = NULL;
	map = NULL;

	if (argc != 2)
	{
		printf("error\n");
		return(1);
	}
	(void) argv;
//	parsing(argv[1], &texture, &map);
	return (0);
}
