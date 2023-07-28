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
	else if (ft_strncmp(cmds[i], "NO\0", 3) == 0
		|| ft_strncmp(cmds[i], "SO\0", 3) == 0
		|| ft_strncmp(cmds[i], "WE\0", 3) == 0
		|| ft_strncmp(cmds[i], "EA\0", 3) == 0)
		return (0);
	else 
	{
		ft_putstr_fd("Error\nImpossible en lecture\n", 2);
		return (1);
	}
	return (0);
}

// ******************************************************************** //
// free les path si une erreur survient:
static void	free_path_texture(t_texture *texture)
{
	if (texture->north != NULL)
		free(texture->north);
	if (texture->south != NULL)
		free(texture->south);
	if (texture->west != NULL)
		free(texture->west);
	if (texture->east != NULL)
		free(texture->east);
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
}

static int	msg_error_texture(t_texture *texture, int flag)
{
	(void)texture;
	if (flag == 1)
		ft_putstr_fd("Error\nno texture file\n", 2);
	if (flag == 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("texture file cannot be opened in read moden\n", 2);
	}
	if (flag == 3)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("texture file already exists\n", 2);
	}
	if (flag == 4)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("FLOOR\n", 2);
	}
	return (1);
}

// teste l ouverture des fichier textures et stocke leur emplacements:
static	int	check_direction(t_texture *texture, char **cmds, int i)
{
	int	fd;

	fd = 0;
	if (cmds[i + 1] == NULL)
	{
		msg_error_texture(texture, 1);
		return (1);
	}
	fd = init_texture(texture, cmds, i);
	if (fd == -1)
	{
		msg_error_texture(texture, 2);
		return (1);
	}
	if (fd == -42)
	{
		msg_error_texture(texture, 3);
		return (1);
	}
	if (check_floor_ceiling(texture, cmds, i) == 1)
	{
		msg_error_texture(texture, 3);
		return (1);
	}
	return (0);
}

// ***************************************************************************** //
// Compare la direction du fichier:
static int	strcmp_texture(char **cmds, int i)
{
	if (ft_strncmp(cmds[i], "NO\0", 3) == 0
		|| ft_strncmp(cmds[i], "SO\0", 3) == 0
		|| ft_strncmp(cmds[i], "WE\0", 3) == 0
		|| ft_strncmp(cmds[i], "EA\0", 3) == 0
		|| ft_strncmp(cmds[i], "F\0", 2) == 0
		|| ft_strncmp(cmds[i], "C\0", 2) == 0)
		return (0);
	else
		return (1);
}

// Verifie l ecriture dans le fichier ligne par ligne:
static int	check_texture(t_texture *texture, char *line)
{
	char	**cmds;
	int		i;

	i = 0;
	line = ft_strtrim(line, "\n");
	cmds = ft_split(line, ' ');
	free(line);
	while (cmds[i])
	{
		if (strcmp_texture(cmds, i) == 0)
		{
			if (check_direction(texture, cmds, i) == 1)
			{
				ft_freestrs(cmds);
				free_path_texture(texture);
				return (1);
			}
		}
		else
		{
			ft_freestrs(cmds);
			ft_putstr_fd("Error\nInvalid line\n", 2);
			free_path_texture(texture);
			return (1);
		}
		i += 2;
	}
	ft_freestrs(cmds);
	return (0);
}

// ***************************************************************************** //
// Parcoure le fichier, copmte le nombre de ligne et
// verifie les fichiers texture:
int	parse_texture(t_texture *texture, int fd_map, int *nb_line)
{
	char	*line;
	int		line_max;
	int		nb_texture;

	line_max = 0;
	nb_texture = 0;
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	while (1)
	{
		line = get_next_line(fd_map);
		if (line == NULL)
			break ;
		if  (*nb_line != -1 && nb_texture < 7)
		{
			if (check_texture(texture, line) == 1)
				*nb_line = -1;
			else
			{
				*nb_line += 1;
				nb_texture++;
			}
		}
		free(line);
		line_max++;
	}
	close(fd_map);
	return (line_max);
}
