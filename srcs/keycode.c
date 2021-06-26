#include "cub3d.h"

int		key_press(int keycode, t_mlx *mlx)
{
	//imgs_init(mlx);
	if (keycode == KEY_W)
		key_w(mlx);
	else if (keycode == KEY_S)
		key_s(mlx);
	else if (keycode == KEY_A)
		key_a(mlx);
	else if (keycode == KEY_D)
		key_d(mlx);
	else if (keycode == KEY_LEFT)
		key_left(mlx);
	else if (keycode == KEY_RIGHT)
		key_right(mlx);
	else if (keycode == KEY_ESC)
		ft_close(mlx);
	return (0);
}

void	key_w(t_mlx *mlx)
{
	if (mlx->info->map[(int)mlx->param->pos_y][(int)(mlx->param->pos_x
				+ mlx->param->dir_x * mlx->param->movespeed)] != '1')
		mlx->param->pos_x += mlx->param->dir_x * mlx->param->movespeed;
	if (mlx->info->map[(int)(mlx->param->pos_y + mlx->param->dir_y
				* mlx->param->movespeed)][(int)mlx->param->pos_x] != '1')
		mlx->param->pos_y += mlx->param->dir_y * mlx->param->movespeed;
}

void	key_s(t_mlx *mlx)
{
	if (mlx->info->map[(int)mlx->param->pos_y][(int)(mlx->param->pos_x
				- mlx->param->dir_x * mlx->param->movespeed)] != '1')
		mlx->param->pos_x -= mlx->param->dir_x * mlx->param->movespeed;
	if (mlx->info->map[(int)(mlx->param->pos_y - mlx->param->dir_y
				* mlx->param->movespeed)][(int)mlx->param->pos_x] != '1')
		mlx->param->pos_y -= mlx->param->dir_y * mlx->param->movespeed;
}

void	key_a(t_mlx *mlx)
{
	if (mlx->info->map[(int)mlx->param->pos_y][(int)(mlx->param->pos_x
				- mlx->param->plane_x * mlx->param->movespeed)] != '1')
		mlx->param->pos_x -= mlx->param->plane_x * mlx->param->movespeed;
	if (mlx->info->map[(int)(mlx->param->pos_y - mlx->param->plane_y
				* mlx->param->movespeed)][(int)mlx->param->pos_x] != '1')
		mlx->param->pos_y -= mlx->param->plane_y * mlx->param->movespeed;
}

void	key_d(t_mlx *mlx)
{
	if (mlx->info->map[(int)mlx->param->pos_y][(int)(mlx->param->pos_x
				+ mlx->param->plane_x * mlx->param->movespeed)] != '1')
		mlx->param->pos_x += mlx->param->plane_x * mlx->param->movespeed;
	if (mlx->info->map[(int)(mlx->param->pos_y + mlx->param->plane_y
				* mlx->param->movespeed)][(int)mlx->param->pos_x] != '1')
		mlx->param->pos_y += mlx->param->plane_y * mlx->param->movespeed;
}
