#include "cub3d.h"

void key_left(t_mlx *mlx)
{
	double olddirX;
	double oldplaneX;

	olddirX = mlx->param->dirX;
	oldplaneX = mlx->param->planeX;
	mlx->param->dirX = mlx->param->dirX * cos(-mlx->param->rotspeed) - mlx->param->dirY * sin(-mlx->param->rotspeed);
	mlx->param->dirY = olddirX * sin(-mlx->param->rotspeed) + mlx->param->dirY * cos(-mlx->param->rotspeed);
	mlx->param->planeX = mlx->param->planeX * cos(-mlx->param->rotspeed) - mlx->param->planeY * sin(-mlx->param->rotspeed);
	mlx->param->planeY = oldplaneX * sin(-mlx->param->rotspeed) + mlx->param->planeY * cos(-mlx->param->rotspeed);
}

void key_right(t_mlx *mlx)
{
	double olddirX;
	double oldplaneX;

	olddirX = mlx->param->dirX;
	oldplaneX = mlx->param->planeX;
	mlx->param->dirX = mlx->param->dirX * cos(mlx->param->rotspeed) - mlx->param->dirY * sin(mlx->param->rotspeed);
	mlx->param->dirY = olddirX * sin(mlx->param->rotspeed) + mlx->param->dirY * cos(mlx->param->rotspeed);
	mlx->param->planeX = mlx->param->planeX * cos(mlx->param->rotspeed) - mlx->param->planeY * sin(mlx->param->rotspeed);
	mlx->param->planeY = oldplaneX * sin(mlx->param->rotspeed) + mlx->param->planeY * cos(mlx->param->rotspeed);
}
