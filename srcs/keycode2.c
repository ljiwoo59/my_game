#include "cub3d.h"

void	key_left(t_mlx *mlx)
{
	double olddir_x;
	double oldplane_x;

	olddir_x = mlx->param->dir_x;
	oldplane_x = mlx->param->plane_x;
	mlx->param->dir_x = mlx->param->dir_x * cos(-mlx->param->rotspeed)
		- mlx->param->dir_y * sin(-mlx->param->rotspeed);
	mlx->param->dir_y = olddir_x * sin(-mlx->param->rotspeed)
		+ mlx->param->dir_y * cos(-mlx->param->rotspeed);
	mlx->param->plane_x = mlx->param->plane_x * cos(-mlx->param->rotspeed)
		- mlx->param->plane_y * sin(-mlx->param->rotspeed);
	mlx->param->plane_y = oldplane_x * sin(-mlx->param->rotspeed)
		+ mlx->param->plane_y * cos(-mlx->param->rotspeed);
}

void	key_right(t_mlx *mlx)
{
	double olddir_x;
	double oldplane_x;

	olddir_x = mlx->param->dir_x;
	oldplane_x = mlx->param->plane_x;
	mlx->param->dir_x =
		mlx->param->dir_x * cos(mlx->param->rotspeed)
		- mlx->param->dir_y * sin(mlx->param->rotspeed);
	mlx->param->dir_y =
		olddir_x * sin(mlx->param->rotspeed)
		+ mlx->param->dir_y * cos(mlx->param->rotspeed);
	mlx->param->plane_x =
		mlx->param->plane_x * cos(mlx->param->rotspeed)
		- mlx->param->plane_y * sin(mlx->param->rotspeed);
	mlx->param->plane_y =
		oldplane_x * sin(mlx->param->rotspeed)
		+ mlx->param->plane_y * cos(mlx->param->rotspeed);
}
