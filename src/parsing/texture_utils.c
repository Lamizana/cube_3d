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

int	fd_error(int fd)
{
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
	return (0);
}

// Counts the number of orders in the line //
int	nb_cmds(char **cmds)
{
	int	i;

	i = 0;
	if (!cmds)
		return (0);
	while (cmds[i])
		i++;
	return (i);
}

int	str_isdigit(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i]) < '0' || line[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
