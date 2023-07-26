#include "../../include/cub3d.h"

static int	init_texture(t_texture *texture, char *line)
{
	(void)texture;
	(void)line;
	return (0);
}

int	parse_texture(t_texture *texture, int fd_map)
{
	char	*line;
	int		nb_line;

	nb_line = 0;
	while (1)
	{
		line = get_next_line(fd_map);
		if (line == NULL)
			break ;
		if (init_texture(texture, line) == 1)
			return (1);
		nb_line++;
		if (line)
			free(line);
	}
	return (nb_line);
}
