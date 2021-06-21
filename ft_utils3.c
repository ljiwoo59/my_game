#include "cub3d.h"

void	dir_set(t_mlx *mlx, int i)
{
	if (i == 1)
	{
		mlx->info->init_dirX = -1;
		mlx->info->init_dirY = 0;
	}
	else if (i == 2)
	{
		mlx->info->init_dirX = 1;
		mlx->info->init_dirY = 0;
	}
	else if (i == 3)
	{
		mlx->info->init_dirX = 0;
		mlx->info->init_dirY = 1;
	}
	else if (i == 4)
	{
		mlx->info->init_dirX = 0;
		mlx->info->init_dirY = -1;
	}
}
