#include "../../include/cub3d.h"
#include <stdlib.h>

int	parse_fill_check(t_map *map, char *line, int index)
{
	map->map[index] = ft_strdup(line);
	return (0);
}

int	init_map(t_map *map, int nb_line)
{
	char	**map_tmp;

	map_tmp = malloc(sizeof(char *) * (nb_line + 1));
	if (!map_tmp)
	{
		ft_putendl_fd("Error\nappend with a malloc", 2);
		return (1);
	}
	map->map = map_tmp;
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
	while (check == 0)
	{
		if (i >= nb_line)
		{
			line = get_next_line(map->fd_map);
			if (line == NULL)
				break ;
			if (line)
			{
				check = parse_fill_check(map, line, (i - l_to_start));
				printf("%s\n", map->map[i - l_to_start]);
				free(line);
			}
		}
		i++;
	}	
	return (0);
}
