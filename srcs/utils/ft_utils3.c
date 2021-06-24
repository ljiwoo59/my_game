#include "cub3d.h"

void	dir_set(t_mlx *mlx, int i)
{
	if (i == 1)
	{
		mlx->info->init_dir_x = -1;
		mlx->info->init_dir_y = 0;
	}
	else if (i == 2)
	{
		mlx->info->init_dir_x = 1;
		mlx->info->init_dir_y = 0;
	}
	else if (i == 3)
	{
		mlx->info->init_dir_x = 0;
		mlx->info->init_dir_y = 1;
	}
	else if (i == 4)
	{
		mlx->info->init_dir_x = 0;
		mlx->info->init_dir_y = -1;
	}
}

int		ft_close(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < ft_sstrlen(mlx->info->map))
		free(mlx->info->map[i++]);
	free(mlx->info->map);
	free(mlx->info->path_no);
	free(mlx->info->path_so);
	free(mlx->info->path_we);
	free(mlx->info->path_ea);
	free(mlx->info);
	free(mlx->param);
	free(mlx->img);
	free(mlx);
	exit(0);
}