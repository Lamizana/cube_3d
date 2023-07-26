#ifndef CUB3D_PROTO_H
# define CUB3D_PROTO_H

# include "cub3d.h"

/*          PARSING                */

int		parsing(char *file, t_texture *texture, t_map *map);
int		parse_texture(t_texture *texture);

/*				close and exit				*/

void	close_map(t_texture *text, t_map *map);

#endif
