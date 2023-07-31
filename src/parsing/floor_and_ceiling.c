#include "../../include/cub3d.h"

// Verifie les valeurs des couleurs //
static int	check_number(int table_rgb[])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (table_rgb[i] < 0 || table_rgb[i] > 255)
		{
			msg_error_texture(6);
			return (1);
		}
		i++;
	}
	return (0);
}

static int rgb_table(int table_rgb[], char **cmds)
{
	char **tmp;
	int	i;

	i = 0;
	while (cmds[i])
		printf("cdms: %s\n", cmds[i++]);
	tmp = trim_and_split(cmds[1], "\n", ',');
	// if (nb_cmds(tmp) != 3)
	// {
		// ft_freestrs(tmp);
		// msg_error_texture(6);
		// return (1);
	// }
	table_rgb[0] = ft_atoi(tmp[0]);
	table_rgb[1] = ft_atoi(tmp[1]);
	table_rgb[2] = ft_atoi(tmp[2]);
	ft_freestrs(tmp);
	if (check_number(table_rgb) == 1)
		return (1);
	printf("rgb_color[0] = %d\n", table_rgb[0]);
	printf("rgb_color[1]= %d\n", table_rgb[1]);
	printf("rgb_color[2] = %d\n", table_rgb[2]);
	return (0);
}

// Checks floor and ceiling format //
int	check_floor_ceiling(t_texture *texture, char **cmds)
{
	int	flag;

	flag = 0;
	if ((ft_strncmp(cmds[0], "F\0", 2) == 0 && texture->f[0] != -42)
		|| (ft_strncmp(cmds[0], "C\0", 2) == 0 && texture->c[0] != -42))
	{
		msg_error_texture(5);
		flag = 1;
	}
	if (ft_strncmp(cmds[0], "F\0", 2) == 0 && texture->f[0] == -42)
	{
		if (rgb_table(texture->f, cmds) == 1)
			return (1);
	}
	else if (ft_strncmp(cmds[0], "C\0", 2) == 0 && texture->c[0] == -42)
	{
		if (rgb_table(texture->c, cmds) == 1)
			return (1);
	}
	if (strcmp_texture(cmds, 0) == 1 || flag == 1)
		return (1);
	return (0);
}
