#include "../../include/cub3d.h"

void	msg_invalid_char(char c)
{
	ft_putstr_fd("Error\n\"", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\" is not a valid char", 2);
}
