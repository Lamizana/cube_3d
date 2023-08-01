#include "../../include/cub3d.h"

static	int	ft_replace(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			line[i] = ',';
		i++;
	}
	return (0);
}

static char	**replace_color_rgb(char *line, t_texture *texture, int i)
{
	char	**cmds;

	if (ft_replace(line) == 1)
	{
		texture->nb_texture = -1;
		msg_error_texture(4);
		return (NULL);
	}
	line[i + 1] = ',';
	cmds = trim_and_split(line, "\n", ',');
	return (cmds);
}

char	**create_cmds(char *line, t_texture *texture)
{
	int		i;
	char	**cmds;

	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ' || line [i] == '\t')
			i++;
		if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')
		{
			cmds = replace_color_rgb(line, texture, i);
			return (cmds);
		}
		else
		{
			cmds = trim_and_split(line, "\n", ' ');
			return (cmds);
		}
		i++;
	}
	return (NULL);
}
