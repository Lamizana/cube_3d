#include "../../include/cub3d.h"
#include <stdlib.h>

int	parse_fill_check(t_map *map, char *line, int index)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(ft_char_in_set(line[i], "01WESN \n\t")))
		{
			ft_putendl_fd("Error", 2);
			ft_putchar_fd(line[i], 2);
			ft_putendl_fd(" is not a valid char", 2);
			return (1);
		}
		i++;
	}
	map->map[index] = ft_strdup(line);
	return (0);
}

int	init_map(t_map *map, int nb_line)
{
	map->map = calloc((nb_line + 1), sizeof(char *));
	if (!map->map)
	{
		ft_putendl_fd("Error\nappend with a malloc", 2);
		return (1);
	}
	return (0);
}

int	parse_map(t_map *map, int l_to_start, int nb_line)
{
	char	*line;
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (init_map(map, (nb_line - l_to_start)))
		return (1);
	while (1)
	{
		line = get_next_line(map->fd_map);
		if (line == NULL)
			break ;
		if (line && i >= l_to_start && check == 0)
		{
			check = parse_fill_check(map, line, (i - l_to_start));
			printf("%s", map->map[i - l_to_start]);
		}
		free(line);
		i++;
	}
	map->map[i - l_to_start] = NULL;
	return (check);
}
