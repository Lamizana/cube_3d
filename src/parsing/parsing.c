#include "../../include/cub3d.h"

int	check_extension(char *extension)
{
	int	i;

	i = 0;
	while (extension && extension[i])
	{
		if (i > 0 && extension[i] == '.' && extension[i +1] == 'c'
			&& extension[i + 2] == 'u' && extension[i + 3] == 'b'
			&& extension[i + 4] == '\0')
			return (0);
		i++;
	}
	ft_putendl_fd("error", 2);
	return (1);
}

int	parsing(char *file, t_texture *texture, t_map *map)
{
	if (check_extension(file))
		return (1);
	map = malloc(sizeof(t_map) * 2);
	map->fd_map = open(file, O_RDONLY);
	if (map->fd_map < 0)
	{
		ft_putendl_fd("error", 2);
		return (1);
	}
	(void)texture;
	(void)map;
//	if open map;
//	init struct_
	// if(parse_texture(map))
		// close_map(map);
	// if (parse_map(map))
		// close_map(map);
	close(map->fd_map);
	return (0);
}
