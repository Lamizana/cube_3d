#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("error\n");
		return	(1);
	}
	parsing(argv[1]);
	return (0);
}
