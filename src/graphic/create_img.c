#include "../../include/cub3d.h"

void	create_img(mlx_image_t *img, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			mlx_put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}

static unsigned long	create_rgba(int r, int g, int b, int a)
{
	unsigned long	rgb;

	rgb = ((r & 0xff) << 24) + ((g & 0xff) << 16)
		+ ((b & 0xff) << 8) + (a & 0xff);
	return (rgb);
}

unsigned long	rgb_color(t_param *param)
{
	unsigned long	rgb;

	rgb = create_rgba(param->text->f[0], param->text->f[1],
			param->text->f[2], 50);
	return (rgb);
}
