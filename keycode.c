#include "cub3d.h"

int	key_press(int keycode, t_mlx *mlx)
{
	imgs_init(mlx);
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
		_close(mlx);	
	return (0);
}

void key_w(t_mlx *mlx)
{
	if (mlx->info->map[(int)mlx->param->posY][(int)(mlx->param->posX + mlx->param->dirX * mlx->param->movespeed)] != '1')
		mlx->param->posX += mlx->param->dirX * mlx->param->movespeed;
	if (mlx->info->map[(int)(mlx->param->posY + mlx->param->dirY * mlx->param->movespeed)][(int)mlx->param->posX] != '1')
		mlx->param->posY += mlx->param->dirY * mlx->param->movespeed;
}

void key_s(t_mlx *mlx)
{
	if (mlx->info->map[(int)mlx->param->posY][(int)(mlx->param->posX - mlx->param->dirX * mlx->param->movespeed)] != '1')
		mlx->param->posX -= mlx->param->dirX * mlx->param->movespeed;
	if (mlx->info->map[(int)(mlx->param->posY - mlx->param->dirY * mlx->param->movespeed)][(int)mlx->param->posX] != '1')
		mlx->param->posY -= mlx->param->dirY * mlx->param->movespeed;
}

void key_a(t_mlx *mlx)
{
	if (mlx->info->map[(int)mlx->param->posY][(int)(mlx->param->posX - mlx->param->planeX * mlx->param->movespeed)] != '1')
		mlx->param->posX -= mlx->param->planeX * mlx->param->movespeed;
	if (mlx->info->map[(int)(mlx->param->posY - mlx->param->planeY * mlx->param->movespeed)][(int)mlx->param->posX] != '1')
		mlx->param->posY -= mlx->param->planeY * mlx->param->movespeed;	
}

void key_d(t_mlx *mlx)
{
	if (mlx->info->map[(int)mlx->param->posY][(int)(mlx->param->posX + mlx->param->planeX * mlx->param->movespeed)] != '1')
		mlx->param->posX += mlx->param->planeX * mlx->param->movespeed;
	if (mlx->info->map[(int)(mlx->param->posY + mlx->param->planeY * mlx->param->movespeed)][(int)mlx->param->posX] != '1')
		mlx->param->posY += mlx->param->planeY * mlx->param->movespeed;	
}
