#include "../../include/cub3d.h"

// Initialize texture variables //
void	init_texture(t_texture *texture)
{
	int	i;

	if (!texture)
		return ;
	i = 0;
	while (i < 3)
	{
		texture->f[i] = -42;
		texture->c[i] = -42;
		i++;
	}
	texture->nb_texture = 0;
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
}
