#include "../../include/cub3d.h"

static int	strdup_texture_north(t_texture *texture, char **cmds, int i)
{
	int	fd;

	fd = 0;
	if (texture->north != NULL)
		return (-42);
	if (cmds[i + 2] != NULL)
		return (-2);
	fd = open(cmds[i + 1], O_RDONLY);
	texture->north = ft_strdup(cmds[i + 1]);
	return (fd);
}

static int	strdup_texture_south(t_texture *texture, char **cmds, int i)
{
	int	fd;

	fd = 0;
	if (texture->south != NULL)
		return (-42);
	if (cmds[i + 2] != NULL)
		return (-2);
	fd = open(cmds[i + 1], O_RDONLY);
	texture->south = ft_strdup(cmds[i + 1]);
	return (fd);
}

static int	strdup_texture_west(t_texture *texture, char **cmds, int i)
{
	int	fd;

	fd = 0;
	if (texture->west != NULL)
		return (-42);
	if (cmds[i + 2] != NULL)
		return (-2);
	fd = open(cmds[i + 1], O_RDONLY);
	texture->west = ft_strdup(cmds[i + 1]);
	return (fd);
}

static int	strdup_texture_east(t_texture *texture, char **cmds, int i)
{
	int	fd;

	fd = 0;
	if (texture->east != NULL)
		return (-42);
	if (cmds[i + 2] != NULL)
		return (-2);
	fd = open(cmds[i + 1], O_RDONLY);
	texture->east = ft_strdup(cmds[i + 1]);
	return (fd);
}

int	init_path_texture(t_texture *texture, char **cmds, int i)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(cmds[i], "NO\0", 3) == 0)
		fd = strdup_texture_north(texture, cmds, i);
	else if (ft_strncmp(cmds[i], "SO\0", 3) == 0)
		fd = strdup_texture_south(texture, cmds, i);
	else if (ft_strncmp(cmds[i], "WE\0", 3) == 0)
		fd = strdup_texture_west(texture, cmds, i);
	else if (ft_strncmp(cmds[i], "EA\0", 3) == 0)
		fd = strdup_texture_east(texture, cmds, i);
	texture->nb_texture++;
	printf("nb_texture: %d\n", texture->nb_texture);
	printf("line: %s\n", cmds[i + 1]);
	return (fd);
}
