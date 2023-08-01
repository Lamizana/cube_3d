#ifndef CUB3D_PROTO_H
# define CUB3D_PROTO_H

# include "cub3d.h"

/********************* PARSING *********************/
int		parsing(char *file, t_texture *texture, t_map *map);
int		parse_map(t_map *map, int l_to_start, int nb_line);
int		wall_around_map(t_map *map, int index_max);

int		init_path_texture(t_texture *texture, char **cmds, int i);
int		parse_texture(t_texture *texture, int fd_map, int *nb_line);
int		check_rgb_format(t_texture *texture, char **cmds);
char	**create_cmds(char *line, t_texture *texture);
// texture_utils.c //
int		fd_error(int fd);
int		nb_cmds(char **cmds);
int		str_isdigit(char *line);
int		strcmp_texture(char **cmds, int i);
char	**trim_and_split(char *line, char *set_trim, char c2_split);

/********** STRUCTURE INITIALIZATION **************/
void	init_texture(t_texture *texture);

/***************** CLOSE AND EXIT *****************/
void	close_map(t_texture *text, t_map *map);
void	close_texture(t_texture *text, int flag);
void	close_strucmap(t_map *map);

/********************* ERROR **********************/
int		msg_invalid_char(char c);
void	msg_error_texture(int flag);
void	msg_color_error(char *color);
int		msg_character(int character);	

#endif
