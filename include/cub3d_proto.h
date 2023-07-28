#ifndef CUB3D_PROTO_H
# define CUB3D_PROTO_H

# include "cub3d.h"

/*          PARSING                */

int		parsing(char *file, t_texture *texture, t_map *map);
int		parse_texture(t_texture *texture, int fd_map, int *nb_line);
int		init_texture(t_texture *texture, char **cmds, int i);
int		parse_map(t_map *map, int l_to_start, int nb_line);
int	wall_around_map(t_map *map, int index_max);

/*				close and exit				*/

void	close_map(t_texture *text, t_map *map);
void	close_texture(t_texture *text);
void	close_strucmap(t_map *map);

/*				error					*/
void	msg_invalid_char(char c);

#endif
