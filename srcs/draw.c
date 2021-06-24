#include "cub3d.h"

void	wall_color(t_mlx *mlx, int y, int x_start)
{
	int pos;

	pos = y * WIDTH + x_start;
	mlx->param->tex_y = (int)mlx->param->tex_pos;
	mlx->param->tex_pos += mlx->param->step;
	if (mlx->param->side == 1)
	{
		if (mlx->param->step_y == 1)
			mlx->img->data[pos] = mlx->img->texture2[mlx->param->tex_y *
				mlx->img->height + mlx->param->tex_x];
		else
			mlx->img->data[pos] = mlx->img->texture[mlx->param->tex_y *
				mlx->img->height + mlx->param->tex_x];
	}
	else
	{
		if (mlx->param->step_x == 1)
			mlx->img->data[pos] = mlx->img->texture4[mlx->param->tex_y *
				mlx->img->height + mlx->param->tex_x];
		else
			mlx->img->data[pos] = mlx->img->texture3[mlx->param->tex_y *
				mlx->img->height + mlx->param->tex_x];
	}
}

void	draw_line(t_mlx *mlx, int x_start)
{
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		if (y < mlx->param->y_start)
			mlx->img->data[(y * WIDTH + x_start)] = mlx->info->rgb_c;
		else if (y > mlx->param->y_end)
			mlx->img->data[(y * WIDTH + x_start)] = mlx->info->rgb_f;
		else
			wall_color(mlx, y, x_start);
	}
}
