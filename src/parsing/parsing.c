int	parsing(char *map, t_texture *texture, t_map *map)
{
//	verif .cub
//	if open map;
//	init struct_
	if(parse_texture(map))
		close_map(map);
	if (parse_map(map))
		close_map(map);
}
