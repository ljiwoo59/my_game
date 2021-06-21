#include "cub3d.h"

void	r_param_set2(t_mlx *mlx)
{
	mlx->param->wallX -= floor(mlx->param->wallX);
	mlx->param->texX = mlx->param->wallX * (double)(mlx->img->width);
	mlx->param->step = 1.0 * mlx->img->height / mlx->param->lineHeight;
	mlx->param->texPos = (mlx->param->y_start - HEIGHT / 2 + mlx->param->lineHeight / 2) * mlx->param->step;
}

void	r_param_set(t_mlx *mlx, int x)
{
	if (mlx->param->side == 0)
	{
		mlx->param->perpWallDist = (mlx->param->mapX - mlx->param->posX + (1 - mlx->param->stepX) / 2) / mlx->param->rayDirX;
		mlx->param->wallX = mlx->param->posY + mlx->param->perpWallDist * mlx->param->rayDirY;
	}
	else
	{
		mlx->param->perpWallDist = (mlx->param->mapY - mlx->param->posY + (1 - mlx->param->stepY) / 2) / mlx->param->rayDirY;
		mlx->param->wallX = mlx->param->posX + mlx->param->perpWallDist * mlx->param->rayDirX;
	}
	mlx->param->lineHeight = (int)(HEIGHT / mlx->param->perpWallDist);
	mlx->param->y_start = -mlx->param->lineHeight / 2 + HEIGHT / 2;
	if (mlx->param->y_start < 0)
		mlx->param->y_start = 0;
	mlx->param->y_end = mlx->param->lineHeight / 2 + HEIGHT / 2;
	if (mlx->param->y_end >= HEIGHT)
		mlx->param->y_end = HEIGHT - 1;
	r_param_set2(mlx);
	draw_line(mlx, x);
}

void	dda_set(t_mlx *mlx)
{
	if (mlx->param->sideDistX < mlx->param->sideDistY)
	{	
		mlx->param->sideDistX += mlx->param->deltaDistX;
		mlx->param->mapX += mlx->param->stepX;
		mlx->param->side = 0;
	}
	else
	{
		mlx->param->sideDistY += mlx->param->deltaDistY;
		mlx->param->mapY += mlx->param->stepY;
		mlx->param->side = 1;
	}
	if (mlx->info->map[mlx->param->mapY][mlx->param->mapX] == '1')
		mlx->param->hit = 1;
}

int	rendering(t_mlx *mlx)
{
	int x;
	
	x = -1;
	while (++x < WIDTH)
	{
		r_param_init(mlx, x);
		while (mlx->param->hit == 0)
			dda_set(mlx);
		r_param_set(mlx, x);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img->img_ptr, 0, 0);
	return (0);
}

int	cub3d(t_mlx *mlx)
{
	
	if (!(mlx->param = (t_param *)malloc(sizeof(t_param))))
		error();
	if (!(mlx->img = (t_img *)malloc(sizeof(t_img))))
		error();
	if (!(mlx->mlx_ptr = mlx_init()))
		error();
	if (!(mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub3d")))
		error();
	program_init(mlx);
	texture_init(mlx);
	imgs_init(mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 0, &key_press, mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_EXIT, 0, &close, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &rendering, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
