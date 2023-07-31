#include "../../include/cub3d.h"

// Tests the opening of texture files and stores their locations //
static	int	check_direction(t_texture *texture, char **cmds, int i)
{
	int	fd;

	fd = 0;
	if (cmds[i + 1] == NULL)
	{
		msg_error_texture(1);
		return (1);
	}
	fd = init_path_texture(texture, cmds, i);
	if (fd == -1)
	{
		msg_error_texture(2);
		return (1);
	}
	else if (fd == -42)
	{
		msg_error_texture(3);
		return (1);
	}
	else if (fd == -2)
	{
		msg_error_texture(4);
		return (1);
	}
	if (check_floor_ceiling(texture, cmds) == 1)
		return (1);
	return (0);
}

static void	free_path_and_str(t_texture *texture, char **cmds, int flag)
{
	ft_freestrs(cmds);
	free_path_texture(texture);
	if (flag == 1)
		msg_error_texture(4);
}

// Checks the writing in the file line by line //
static int	check_texture(t_texture *texture, char *line)
{
	char	**cmds;
	int		i;

	i = 0;
	cmds = trim_and_split(line, "\n", ' ');
	while (cmds[i])
	{
		if (strcmp_texture(cmds, i) == 0)
		{
			if (check_direction(texture, cmds, i) == 1)
			{
				free_path_and_str(texture, cmds, 0);
				return (1);
			}
		}
		else
		{
			free_path_and_str(texture, cmds, 1);
			return (1);
		}
		i += 2;
	}
	ft_freestrs(cmds);
	return (0);
}

// Checks the number of textures //
static int	check_nb_texture(t_texture *texture, int fd_map)
{
	close(fd_map);
	if (texture->nb_texture == 0)
	{
		msg_error_texture(1);
		return (1);
	}
	return (0);
}

// Browse the file, count the number of lines and check texture files //
int	parse_texture(t_texture *texture, int fd_map, int *nb_line)
{
	char	*line;
	int		line_max;

	line_max = 0;
	init_texture(texture);
	while (1)
	{
		line = get_next_line(fd_map);
		if (line == NULL)
			break ;
		if (*nb_line != -1 && texture->nb_texture < 6)
		{
			if (check_texture(texture, line) == 1)
				*nb_line = -1;
			else
				*nb_line += 1;
		}
		free(line);
		line_max++;
	}
	if (check_nb_texture(texture, fd_map) == 1)
		*nb_line = -1;
	return (line_max);
}
