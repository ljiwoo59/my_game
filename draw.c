#include "cub3d.h"

void	wall_color(t_mlx *mlx, int y, int x_start)
{
	int pos;

	pos = y * WIDTH + x_start;
	mlx->param->texY = (int)mlx->param->texPos;
	mlx->param->texPos += mlx->param->step;
	if (mlx->param->side == 1)
	{
		if (mlx->param->stepY == 1)
			mlx->img->data[pos] = mlx->img->texture2[mlx->param->texY * mlx->img->height + mlx->param->texX]; // S
		else
			mlx->img->data[pos] = mlx->img->texture[mlx->param->texY * mlx->img->height + mlx->param->texX]; //N
	}
	else
	{
		if (mlx->param->stepX == 1)
			mlx->img->data[pos] = mlx->img->texture4[mlx->param->texY * mlx->img->height + mlx->param->texX]; //E
		else
			mlx->img->data[pos] = mlx->img->texture3[mlx->param->texY * mlx->img->height + mlx->param->texX]; //W
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
