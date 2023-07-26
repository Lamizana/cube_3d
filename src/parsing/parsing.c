#include "../../include/cub3d.h"

static int	check_extension(char *extension)
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
	ft_putendl_fd("Error\nThe extension is incorrect and should be .cub", 2);
	return (1);
}

int	parsing(char *file, t_texture *texture, t_map *map)
{
	int	ret_text;

	if (check_extension(file))
		return (1);
	map = ft_calloc(1, sizeof(t_map));
	map->fd_map = open(file, O_RDONLY);
	if (map->fd_map < 0)
	{
		ft_putendl_fd("Error\nYour map can't open", 2);
		return (1);
	}
	ret_text = parse_texture(texture, map->fd_map);
	if (ret_text == 1)
		close_map(texture, map);
	if (parse_map(map))
		close_map(texture, map);
	return (0);
}
