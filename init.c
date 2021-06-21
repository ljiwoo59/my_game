#include "cub3d.h"

void	program_init(t_mlx *mlx)
{
	mlx->param->posX = mlx->info->init_posX;
	mlx->param->posY = mlx->info->init_posY;
	mlx->param->dirX = mlx->info->init_dirY;
	mlx->param->dirY = mlx->info->init_dirX;
	if (mlx->param->dirX == 0)
	{
		if (mlx->param->dirY == -1)
			mlx->param->planeX = 0.66;
		else
			mlx->param->planeX = -0.66;
	}
	else
		mlx->param->planeX = 0;
	if (mlx->param->dirY == 0)
	{
		if (mlx->param->dirX == -1)
			mlx->param->planeY = -0.66;
		else
			mlx->param->planeY = 0.66;
	}
	else
		mlx->param->planeY  = 0;
	mlx->param->movespeed = 0.5;
	mlx->param->rotspeed = 0.33;
}

void	imgs_init(t_mlx *mlx)
{
	if (!(mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT)))
		error2(10);
	if (!(mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp, &mlx->img->size_l, &mlx->img->endian)))
		error2(9);
}

void	texture_init(t_mlx *mlx)
{
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->info->path_no, &(mlx->img->width), &(mlx->img->height))))
		error();
	if (!(mlx->img->texture = (int *)mlx_get_data_addr(mlx->img->t_ptr, &mlx->img->t_bpp, &mlx->img->t_size_l, &mlx->img->t_endian)))
		error();
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->info->path_so, &(mlx->img->width), &(mlx->img->height))))
		error();
	if (!(mlx->img->texture2 = (int *)mlx_get_data_addr(mlx->img->t_ptr, &mlx->img->t_bpp, &mlx->img->t_size_l, &mlx->img->t_endian)))
		error();
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->info->path_we, &(mlx->img->width), &(mlx->img->height))))
		error();
	if (!(mlx->img->texture3 = (int *)mlx_get_data_addr(mlx->img->t_ptr, &mlx->img->t_bpp, &mlx->img->t_size_l, &mlx->img->t_endian)))
		error();
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->info->path_ea, &(mlx->img->width), &(mlx->img->height))))
		error();
	if (!(mlx->img->texture4 = (int *)mlx_get_data_addr(mlx->img->t_ptr, &mlx->img->t_bpp, &mlx->img->t_size_l, &mlx->img->t_endian)))
		error();
}

void	r_param_init2(t_mlx *mlx)
{
	if (mlx->param->rayDirX < 0)
	{
		mlx->param->stepX = -1;
		mlx->param->sideDistX = (mlx->param->posX - mlx->param->mapX) * mlx->param->deltaDistX;
	}
	else
	{
		mlx->param->stepX = 1;
		mlx->param->sideDistX = (mlx->param->mapX + 1 - mlx->param->posX) * mlx->param->deltaDistX;
	}
	if (mlx->param->rayDirY < 0)
	{
		mlx->param->stepY = -1;
		mlx->param->sideDistY = (mlx->param->posY - mlx->param->mapY) * mlx->param->deltaDistY;
	}
	else
	{
		mlx->param->stepY = 1;
		mlx->param->sideDistY = (mlx->param->mapY + 1 - mlx->param->posY) * mlx->param->deltaDistY;
	}
}

void	r_param_init(t_mlx *mlx, int x)
{
	mlx->param->cameraX = 2 * x / (double)WIDTH - 1;
	mlx->param->rayDirX = mlx->param->dirX + mlx->param->planeX * mlx->param->cameraX;
	mlx->param->rayDirY = mlx->param->dirY + mlx->param->planeY * mlx->param->cameraX;
	mlx->param->mapX = (int)mlx->param->posX;
	mlx->param->mapY = (int)mlx->param->posY;
	mlx->param->deltaDistX = fabs(1 / mlx->param->rayDirX);
	mlx->param->deltaDistY = fabs(1 / mlx->param->rayDirY);
	mlx->param->hit = 0;
	r_param_init2(mlx);
}
