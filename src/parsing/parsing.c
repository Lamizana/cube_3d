#include "../../include/cub3d.h"

int	check_extension(char *extension)
{
	int	i;

	i = 0;
	while (extension && extension[i])
	{
		if (i > 0 && extension[i] == '.' && extension[i +1] == 'c'
			&& extension[i + 2] == 'u' && extension[i + 3] == 'b' && extension[i + 4] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	parsing(char *map, t_texture *texture, t_map *map)
{
	if (check_extension(map))
		return (1);
//	if open map;
//	init struct_
	// if(parse_texture(map))
		// close_map(map);
	// if (parse_map(map))
		// close_map(map);
}
