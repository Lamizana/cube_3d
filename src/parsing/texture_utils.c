#include "../../include/cub3d.h"

// Compares file direction //
int	strcmp_texture(char **cmds, int i)
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

// Free paths if an error occurs //
void	free_path_texture(t_texture *texture)
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

// Replace tabs with spaces and remove '\n' and split spaces //
char	**trim_and_split(char *line, char *set_trim, char c2_split)
{
	int		i;
	char	**cmds;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = c2_split;
		i++;
	}
	line = ft_strtrim(line, set_trim);
	cmds = ft_split(line, c2_split);
	free(line);
	return (cmds);
}
