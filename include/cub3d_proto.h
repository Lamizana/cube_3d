#ifndef CUB3D_PROTO_H
# define CUB3D_PROTO_H

# include "cub3d.h"
# include "cub3d_struct.h"

/*          PARSING                */

int	parsing(char *file, t_texture *texture, t_map *map);
int	parse_texture(char *argv, t_texture *texture);

#endif
