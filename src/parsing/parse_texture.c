#include "../../include/cub3d.h"

// Compares file direction //
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

// Checks floor and ceiling format //
static	int	check_floor_ceiling(t_texture *texture, char **cmds, int i)
{
	int	flag;

	flag = 0;
	printf("%s\n", cmds[i]);
	if ((ft_strncmp(cmds[i], "F\0", 2) == 0 && texture->f[0] != -42)
		|| (ft_strncmp(cmds[i], "C\0", 2) == 0 && texture->c[0] != -42))
		flag = 1;
	if (ft_strncmp(cmds[i], "F\0", 2) == 0 && texture->f[0] == -42)
	{
		printf("f:%d\n", texture->f[0]);
		texture->f[0] = 1;

	}
	else if (ft_strncmp(cmds[i], "C\0", 2) == 0 && texture->c[0] == -42)
	{
		printf("c:%d\n", texture->c[0]);
		texture->c[0] = 1;

	}
	if	(strcmp_texture(cmds, i) == 1 || flag == 1)
		return (1);
	return (0);
}

// ******************************************************************** //
// Free paths if an error occurs //
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
	if (fd == -42)
	{
		msg_error_texture(3);
		return (1);
	}
	if (check_floor_ceiling(texture, cmds, i) == 1)
	{
		msg_error_texture(5);
		return (1);
	}
	return (0);
}

// ************************************************************************* //
// Replace tabs with spaces and remove '\n' and split spaces //
static char	**trim_and_split(char *line, char *set_trim, char c2_split)
{
	int		i;
	char	**cmds;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	line = ft_strtrim(line, set_trim);
	cmds = ft_split(line, c2_split);
	free(line);
	return (cmds);
}

static void free_path_and_str(t_texture *texture, char **cmds, int flag)
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
	if (texture->nb_texture != 6)
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
		return (1);
	return (line_max);
}
