#include "../../include/cub3d.h"

void	rot_z(t_graph )
{
	int		i;
	float	x_tmp;
	double	teta;

	i = 0;
	teta = graph.angz * (M_PI / 180);
	while (i < (graph.h * graph.w))
	{
		x_tmp = graph.p2[i].x;
		graph.p2[i].x = graph.p2[i].x * cos(teta) - graph.p2[i].y * sin(teta);
		graph.p2[i].y = x_tmp * sin(teta) + graph.p2[i].y * cos(teta);
		graph.p2[i].z = graph.p2[i].z;
		i++;
	}
}

void	rot_y(t_graph graph)
{
	int		i;
	double	teta;
	float	x_tmp;

	i = 0;
	teta = graph.angy * (M_PI / 180);
	while (i < (graph.h * graph.w))
	{
		x_tmp = graph.p2[i].x;
		graph.p2[i].x = graph.p2[i].x * cos(teta) + graph.p2[i].z * sin(teta);
		graph.p2[i].z = (x_tmp * (-sin(teta))) + graph.p2[i].z * cos(teta);
		graph.p2[i].y = graph.p2[i].y;
		i++;
	}
}

void	rot_x(t_graph graph)
{
	int		i;
	double	teta;
	float	tmp;

	i = 0;
	teta = graph.angx * (M_PI / 180);
	while (i < (graph.h * graph.w))
	{
		tmp = graph.p2[i].z;
		graph.p2[i].x = graph.p2[i].x;
		graph.p2[i].z = graph.p2[i].y * sin(teta) + graph.p2[i].z * cos(teta);
		graph.p2[i].y = graph.p2[i].y * cos(teta) - (tmp * sin(teta));
		i++;
	}
}
