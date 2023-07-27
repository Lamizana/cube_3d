#include "../../include/cub3d.h"
//
// static	int	check_floor_ceiling(t_texture *texture, char **cmds, int i)
// {
	// return (0);
// 
// }
// 
static	int	check_direction(t_texture *texture, char **cmds, int i)
{
	printf("%s\n", cmds[i]);
	if (cmds[i + 1] == NULL)
	{
		ft_freestrs(cmds);
		ft_putstr_fd("Error\nfichier texture inexistant\n", 2);
		return (1);
	}
	if (ft_strncmp(cmds[i], "NO\0", 3) == 0)
		texture->north = open(cmds[i + 1], O_RDONLY);
	else if (ft_strncmp(cmds[i], "SO\0", 3) == 0)
		texture->south = open(cmds[i + 1], O_RDONLY);
	else if (ft_strncmp(cmds[i], "WE\0", 3) == 0)
		texture->west = open(cmds[i + 1], O_RDONLY);
	else if (ft_strncmp(cmds[i], "EA\0", 3) == 0)
		texture->east = open(cmds[i + 1], O_RDONLY);
	if (texture->north == -1 || texture->south == -1
		|| texture->west == -1 || texture->east == -1)
	{
		ft_freestrs(cmds);
		ft_putstr_fd("Error\nImpossible d'ouvrir le fichier texture en lecture\n", 2);
		return (1);
	}
//	if (check_floor_ceiling(texture, cmds, i) == 1)
//		return (1);
	return (0);
}

static int	check_texture(t_texture *texture, char *line)
{
	char	**cmds;
	char	*tmp;
	int		i;

	tmp = ft_strtrim(line, "\n");
	cmds = ft_split(tmp, ' ');
	free(tmp);
	i = 0;
	while (cmds[i])
	{
		if (ft_strncmp(cmds[i], "NO\0", 3) == 0
			|| ft_strncmp(cmds[i], "SO\0", 3) == 0
			|| ft_strncmp(cmds[i], "WE\0", 3) == 0
			|| ft_strncmp(cmds[i], "EA\0", 3) == 0
			|| ft_strncmp(cmds[i], "F\0", 2) == 0
			|| ft_strncmp(cmds[i], "C\0", 2) == 0)
		{
			if (check_direction(texture, cmds, i) == 1)
				return (1);
		}
		else
		{
			ft_freestrs(cmds);
			return (1);
		}
		i += 2;
	}
	ft_freestrs(cmds);
	return (0);
}

int	parse_texture(t_texture *texture, int fd_map, int *nb_line)
{
	char	*line;
	int		check;

	check = 0;
	texture->north = 0;
	texture->south = 0;
	texture->west = 0;
	texture->east = 0;
	while (1)
	{
		line = get_next_line(fd_map);
		if (line == NULL)
			break ;
		if (!check)
			if (check_texture(texture, line) == 1)
				check = 1;
		free(line);
		*nb_line += 1;
	}
	return (*nb_line);
}
