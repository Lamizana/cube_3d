#include "../../include/cub3d.h"

void	msg_color_error(char *color)
{
	ft_putstr_fd(CRED, 2);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(NC, 2);
	ft_putstr_fd(color, 2);
}

int	msg_invalid_char(char c)
{
	msg_color_error(IRED);
	ft_putchar_fd('\"', 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\" is not a valid char", 2);
	ft_putstr_fd(NC, 2);
	return (1);
}

// Returns an error message when parsing a texture //
void	msg_error_texture(int flag)
{
	msg_color_error(IRED);
	if (flag == 1)
		ft_putstr_fd("no texture file\n", 2);
	if (flag == 2)
		ft_putstr_fd("texture file cannot be opened in read mode\n", 2);
	if (flag == 3)
		ft_putstr_fd("texture file already exists\n", 2);
	if (flag == 4)
		ft_putstr_fd("invalid line\n", 2);
	if (flag == 5)
		ft_putstr_fd("floor or ceilling already exists\n", 2);
	if (flag == 6)
		ft_putstr_fd("floor or ceiling values are not valid\n", 2);
	if (flag == 7)
		ft_putstr_fd("number of invalid arguments\n", 2);
	ft_putstr_fd(NC, 2);
}

int	msg_character(int character)
{
	if (!character)
		ft_putendl_fd("Error\nNeed one character", 2);
	if (character)
		ft_putendl_fd("Error\nyou can just put one spawn", 2);
	return (1);
}
