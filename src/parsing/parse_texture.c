#include "../../include/cub3d.h"

static	int	check_floor_ceiling(t_texture *texture, char **cmds, int i)
{
	(void)texture;
	
	if (ft_strncmp(cmds[i], "F\0", 2) == 0)
	{

	}
	else if (ft_strncmp(cmds[i], "C\0", 2) == 0)
	{

	}
	else
		return (1);
	return (0);
}

static	int	check_direction(t_texture *texture, char **cmds, int i)
{
	printf("%s\n", cmds[i +1]);
	if (cmds[i + 1] == NULL)
	{
		ft_freestrs(cmds);
		ft_putstr_fd("Error\nfichier texture inexistant\n", 2);
		return (1);
	}
	if (ft_strncmp(cmds[i], "NO\0", 3) == 0)
		texture->north_fd = open(cmds[i + 1], O_RDONLY);
	else if (ft_strncmp(cmds[i], "SO\0", 3) == 0)
		texture->south_fd = open(cmds[i + 1], O_RDONLY);
	else if (ft_strncmp(cmds[i], "WE\0", 3) == 0)
		texture->west_fd = open(cmds[i + 1], O_RDONLY);
	else if (ft_strncmp(cmds[i], "EA\0", 3) == 0)
		texture->east_fd = open(cmds[i + 1], O_RDONLY);
	else if (check_floor_ceiling(texture, cmds, i) == 1)
		return (1);
	if (texture->north_fd == -1 || texture->south_fd == -1
		|| texture->west_fd == -1 || texture->east_fd == -1)
	{
		ft_freestrs(cmds);
		ft_putstr_fd("Error\nImpossible d'ouvrir le fichier texture en lecture\n", 2);
		return (1);
	}
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
	int		nb_texture;

	check = 0;
	nb_texture = 0;
	while (nb_texture < 7)
	{
		line = get_next_line(fd_map);
		if (line == NULL)
			break ;
		if (!check)
		{
			if (check_texture(texture, line) == 1)
				check = 1;
			else
				nb_texture++;
		}
		free(line);
		*nb_line += 1;
	}
	return (*nb_line);
}
