#ifndef CUB3D_PROTO_H
# define CUB3D_PROTO_H

# include "cub3d.h"

/********************* PARSING *********************/
int		parsing(char *file, t_texture *texture, t_map *map);
int		parse_map(t_map *map, int l_to_start, int nb_line);
int		wall_around_map(t_map *map, int index_max);

int		init_path_texture(t_texture *texture, char **cmds, int i);
int		parse_texture(t_texture *texture, int fd_map, int *nb_line);
int		check_floor_ceiling(t_texture *texture, char **cmds);
// texture_utils.c //
int		strcmp_texture(char **cmds, int i);
void	free_path_texture(t_texture *texture);
char	**trim_and_split(char *line, char *set_trim, char c2_split);
int		nb_cmds(char **cmds);

/********** STRUCTURE INITIALIZATION **************/
void	init_texture(t_texture *texture);

/***************** CLOSE AND EXIT *****************/
void	close_map(t_texture *text, t_map *map);
void	close_texture(t_texture *text);
void	close_strucmap(t_map *map);

/********************* ERROR **********************/
void	msg_invalid_char(char c);
void	msg_error_texture(int flag);
void	msg_color_error(char *color);

#endif
