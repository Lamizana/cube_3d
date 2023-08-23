#include "../../include/cub3d.h"
#include <stdlib.h>

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
			param->text->f[2], 255);
	return (rgb);
}

void	circle_of_character(mlx_image_t *img, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while ((unsigned)i < img->width)
	{
		j = 0;
		while ((unsigned)j < img->height)
		{
			if ((i - 8) * (i - 8) + (j - 8) * (j - 8) <= 8 * 8)
				mlx_put_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

void	dda(t_cam *cam, mlx_image_t *img, uint32_t color)
{
	int		i;
	float	x;
	float	y;
	float	step;
 
	printf("cam- x 2 %lf \t y %lf", cam->x2, cam->y2);
	if (fabs(cam->x2 - cam->x1) >= fabs(cam->y2 - cam->y1))
		step = fabs(cam->x2 - cam->x1);
	else
		step = fabs(cam->y2 - cam->y1);
	printf("------------------step %lf ---------------------\n", step);
	cam->dx = (cam->x2 - cam->x1) / step;
	cam->dy = (cam->y2 - cam->y1) / step;
	x = cam->x1;
	y = cam->y1;
	i = 0;
	while (i <= step)
	{

		printf("X %lf\t y  %lf \n", x ,y );
		mlx_put_pixel(img, x, y, color);
		x += cam->dx;
		y += cam->dy;
		i++;	
	}
}

void	create_line(mlx_image_t *img, t_param *param, uint32_t color)
{
	t_cam	*cam;
/*	int	i;
	int	j;

	i = 0;
	while ((unsigned)i < img->width)
	{
		j = 0;
		while ((unsigned)j < img->height)
		{

			mlx_put_pixel(img, i, j, color);
			j++;
		}
		i++;
	}*/ 
	cam = param->cam;
	cam->px = param->graph->img_p->instances[0].x; 
	cam->py = param->graph->img_p->instances[0].y;
	cam->x1 = cam->px;
	cam->y1 = cam->py;
	if (param->map->pos_init == 'N')
	{
		cam->pa = PI / 2;
		cam->x2 = (cos(cam->pa)) + 32 + cam->px;
		cam->y2 = (sin(cam->pa)) + 32 + cam->py;
	}
	else if (param->map->pos_init == 'S')
	{
		cam->pa = 3 * PI / 2;
		cam->x2 = cos(cam->pa)+ 32  + cam->px;
		cam->y2 = sin(cam->pa)+ 32  + cam->py;
	}
	else if (param->map->pos_init == 'W')
	{
		cam->pa = PI;
		cam->x2 =  cos(cam->pa) + 32 + cam->px;
		cam->y2 = sin(cam->pa) + 32 + cam->py;
	} 
	else if (param->map->pos_init == 'E')
	{
		cam->pa = 0;
		cam->x2 = (cos(cam->pa)) + cam->px;
		cam->y2 = (sin(cam->pa)) + cam->py;
	}
	dda(cam, img, color);
}
