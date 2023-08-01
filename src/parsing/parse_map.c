#include "../../include/cub3d.h"

static int	parse_fill_check(t_map *map, char *line, int index)
{
	int		i;
	char	*tmp;
	int		check;

	i = 0;
	check = 0;
	while (line[i] && !check)
	{
		if (!(ft_char_in_set(line[i], "01WESN \n")))
			check = msg_invalid_char(line[i]);
		if (ft_char_in_set(line[i], "WESN"))
		{
			map->pos_nb += 1;
			if (!map->pos_init)
				map->pos_init = line[i];
			if (map->pos_nb > 1)
				check = msg_character(2);
		}
		i++;
	}
	tmp = ft_strtrim(line, "\n");
	map->map[index] = ft_strdup(tmp);
	free(tmp);
	return (check);
}

static int	init_map(t_map *map, int nb_line)
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
		if (line && i >= l_to_start && check == 0 && map->pos_nb <= 1)
			check = parse_fill_check(map, line, (i - l_to_start));
		free(line);
		i++;
	}
	if (check == 0)
		if (wall_around_map(map, (nb_line - l_to_start)))
			check = 1;
	if (check == 0 && !map->pos_init)
		check = msg_character(0);
	return (check);
}
