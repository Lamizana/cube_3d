#include "../../include/cub3d.h"

// Verifir le foRMAT DU SOL:
static int check_floor(t_texture *texture, char **cmds, int i)
{
	// int	a;
	// int	b;
	// int	c;
	// char **tmp;
// 
	// i = 0;
	// tmp = trim_and_split(cmds[i+1], "\n", ',');
	// printf("%s\n", tmp[i]);
	// printf("%s\n", tmp[i+1]);
	// a = ft_atoi(cmds[0]);
	// b = ft_atoi(cmds[2]);
	// c = ft_atoi(cmds[4]);
	// if ((a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255)
			// && (ft_strncmp(cmds[1], ",\0", 2) != 0 
			// || ft_strncmp(cmds[3], ",\0", 2) != 0 
			// || cmds[5] != NULL))
		// printf("ERRRORORORORO\n");
	i = 0;
	(void)texture;
	(void)cmds;

	printf("f:%d\n", texture->f[0]);
	return (0);
}

static int check_ceiling(t_texture *texture, char **cmds, int i)
{

	(void)texture;
	(void)cmds;
	i = 0;
	printf("c:%d\n", texture->c[0]);
	return (0);
}

// Checks floor and ceiling format //
int	check_floor_ceiling(t_texture *texture, char **cmds, int i)
{
	int	flag;

	flag = 0;
	if ((ft_strncmp(cmds[i], "F\0", 2) == 0 && texture->f[0] != -42)
		|| (ft_strncmp(cmds[i], "C\0", 2) == 0 && texture->c[0] != -42))
		flag = 1;
	if (ft_strncmp(cmds[i], "F\0", 2) == 0 && texture->f[0] == -42)
	{
		if (check_floor(texture, cmds, i) == 1)
			return (1);
	}
	else if (ft_strncmp(cmds[i], "C\0", 2) == 0 && texture->c[0] == -42)
	{
		if (check_ceiling(texture, cmds, i) == 1)
			return (1);
	}
	if (strcmp_texture(cmds, i) == 1 || flag == 1)
		return (1);
	return (0);
}
