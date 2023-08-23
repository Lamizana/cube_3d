void	digit_diff_analyser(t_graph)
{
	float	x;
	float	y;
	int		i;

	dda.l = fmax(fabsf(dda.x2 - dda.x1), fabsf(dda.y2 - dda.y1));
	dda.dx = (dda.x2 - dda.x1) / dda.l;
	dda.dy = (dda.y2 - dda.y1) / dda.l;
	x = dda.x1 + 0.5;
	y = dda.y1 + 0.5;
	i = 0;
	color = ft_color(dda);
	while (i < dda.l)
	{
		add_mlx_pixel_put (&vars, (x + vars.frame.midx_win),
			(y + vars.frame.midy_win), color);
		x = x + dda.dx;
		y = y + dda.dy;
		i++;
	}
}
