#include "cub3d.h"

void	program_init(t_mlx *mlx)
{
	mlx->param->pos_x = mlx->info->init_pos_x;
	mlx->param->pos_y = mlx->info->init_pos_y;
	mlx->param->dir_x = mlx->info->init_dir_y;
	mlx->param->dir_y = mlx->info->init_dir_x;
	if (mlx->param->dir_x == 0)
	{
		if (mlx->param->dir_y == -1)
			mlx->param->plane_x = 0.66;
		else
			mlx->param->plane_x = -0.66;
	}
	else
		mlx->param->plane_x = 0;
	if (mlx->param->dir_y == 0)
	{
		if (mlx->param->dir_x == -1)
			mlx->param->plane_y = -0.66;
		else
			mlx->param->plane_y = 0.66;
	}
	else
		mlx->param->plane_y = 0;
	mlx->param->movespeed = 0.5;
	mlx->param->rotspeed = 0.33;
}

void	imgs_init(t_mlx *mlx)
{
	if (!(mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT)))
		error();
	if (!(mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_ptr,
					&mlx->img->bpp, &mlx->img->size_l, &mlx->img->endian)))
		error();
}

void	r_param_init2(t_mlx *mlx)
{
	if (mlx->param->ray_dir_x < 0)
	{
		mlx->param->step_x = -1;
		mlx->param->side_dist_x =
			(mlx->param->pos_x - mlx->param->map_x) * mlx->param->delta_dist_x;
	}
	else
	{
		mlx->param->step_x = 1;
		mlx->param->side_dist_x = (mlx->param->map_x
				+ 1 - mlx->param->pos_x) * mlx->param->delta_dist_x;
	}
	if (mlx->param->ray_dir_y < 0)
	{
		mlx->param->step_y = -1;
		mlx->param->side_dist_y =
			(mlx->param->pos_y - mlx->param->map_y) * mlx->param->delta_dist_y;
	}
	else
	{
		mlx->param->step_y = 1;
		mlx->param->side_dist_y = (mlx->param->map_y
				+ 1 - mlx->param->pos_y) * mlx->param->delta_dist_y;
	}
}

void	r_param_init(t_mlx *mlx, int x)
{
	mlx->param->camera_x = 2 * x / (double)WIDTH - 1;
	mlx->param->ray_dir_x = mlx->param->dir_x
		+ mlx->param->plane_x * mlx->param->camera_x;
	mlx->param->ray_dir_y = mlx->param->dir_y
		+ mlx->param->plane_y * mlx->param->camera_x;
	mlx->param->map_x = (int)mlx->param->pos_x;
	mlx->param->map_y = (int)mlx->param->pos_y;
	mlx->param->delta_dist_x = fabs(1 / mlx->param->ray_dir_x);
	mlx->param->delta_dist_y = fabs(1 / mlx->param->ray_dir_y);
	mlx->param->hit = 0;
	r_param_init2(mlx);
}
