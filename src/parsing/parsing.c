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
	msg_error_texture(11);
	return (1);
}

int	open_map(char *file, t_map *map)
{
	map->fd_map = open(file, O_RDONLY);
	if (map->fd_map < 0)
	{
		msg_error_texture(10);
		return (1);
	}
	return (0);
}

int	parsing(char *file, t_texture *texture, t_map *map)
{
	int	ret_text;
	int	nb_line;

	ret_text = 0;
	if (check_extension(file))
		return (1);
	if (open_map(file, map))
		return (1);
	nb_line = parse_texture(texture, map->fd_map, &ret_text);
	if (ret_text == -1)
		close_map(texture, map);
	if (open_map(file, map))
		return (1);
	if (parse_map(map, ret_text, nb_line))
		close_map(texture, map);
	return (0);
}
