#include "cub3d.h"
extern int worldMap[mapWidth][mapHeight];

void	param_init(t_mlx *mlx)
{
	mlx->param->posX = 22;
	mlx->param->posY = 12;
	mlx->param->dirX = -1;
	mlx->param->dirY = 0;
	mlx->param->planeX = 0;
	mlx->param->planeY = 0.66;
	mlx->param->time = 0;
	mlx->param->oldtime = 0;
}

void	mlxs_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub3d");	
}

void	imgs_init(t_mlx *mlx)
{
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp, &mlx->img->size_l, &mlx->img->endian);
}

int	close(t_mlx *mlx)
{
	free(mlx->param);
	free(mlx->img);
	free(mlx);
	exit(0);
}

void	draw_line(int line_h, int x_start, int y_start, int side, t_mlx *mlx, int stepX, int stepY)
{
	int x;
	
	x = -1;
	while (++x < line_h)
	{
		if (((y_start + x) * WIDTH + x_start) < WIDTH * HEIGHT)
		{
			if (side == 1)
			{
				if (stepY == 1)
					mlx->img->data[(y_start + x) * WIDTH + x_start] = 0xFF0000; //R
				else
					mlx->img->data[(y_start + x) * WIDTH + x_start] = 0x00FF00; //G
			}
			else
			{
				if (stepX == 1)
					mlx->img->data[(y_start + x) * WIDTH + x_start] = 0x0000FF; //B
				else
					mlx->img->data[(y_start + x) * WIDTH + x_start] = 0xFFFF00;
			}
		}
	}
}

int	rendering(t_mlx *mlx)
{
	int x = -1;
	
	while (++x < WIDTH)
	{
		double cameraX = 2 * x / (double)WIDTH - 1;
		double rayDirX = mlx->param->dirX + mlx->param->planeX * cameraX;
		double rayDirY = mlx->param->dirY + mlx->param->planeY * cameraX;
		int mapX = (int)mlx->param->posX;
		int mapY = (int)mlx->param->posY;
		double sideDistX;
		double sideDistY;
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		int stepX;
		int stepY;
		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (mlx->param->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - mlx->param->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (mlx->param->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - mlx->param->posY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - mlx->param->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - mlx->param->posY + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(HEIGHT / perpWallDist);
		int y_start = -lineHeight / 2 + HEIGHT / 2;
		if (y_start < 0)
			y_start = 0;
		if (y_start >= HEIGHT)
			y_start = HEIGHT - 1;
		draw_line(lineHeight, x, y_start, side, mlx, stepX, stepY);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img->img_ptr, 0, 0);
	return (0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	double movespeed = 0.5;
	double rotspeed = 0.33;

	mlx_destroy_image(mlx->mlx_ptr, mlx->img->img_ptr);	
	imgs_init(mlx);
	if (keycode == KEY_W)
	{
		if (worldMap[(int)(mlx->param->posX + mlx->param->dirX * movespeed)][(int)mlx->param->posY] == 0)
			mlx->param->posX += mlx->param->dirX * movespeed;
		if (worldMap[(int)mlx->param->posX][(int)(mlx->param->posY + mlx->param->dirY * movespeed)] == 0)
			mlx->param->posY += mlx->param->dirY * movespeed;
	}	
	else if (keycode == KEY_S)
	{
		if (worldMap[(int)(mlx->param->posX - mlx->param->dirX * movespeed)][(int)mlx->param->posY] == 0)
			mlx->param->posX -= mlx->param->dirX * movespeed;
		if (worldMap[(int)mlx->param->posX][(int)(mlx->param->posY - mlx->param->dirY * movespeed)] == 0)
			mlx->param->posY -= mlx->param->dirY * movespeed;
	}	
	else if (keycode == KEY_A)
	{
		if (worldMap[(int)(mlx->param->posX - mlx->param->planeX * movespeed)][(int)mlx->param->posY] == 0)
			mlx->param->posX -= mlx->param->planeX * movespeed;
		if (worldMap[(int)mlx->param->posX][(int)(mlx->param->posY - mlx->param->planeY * movespeed)] == 0)
			mlx->param->posY -= mlx->param->planeY * movespeed;
	}	
	else if (keycode == KEY_D)
	{
		if (worldMap[(int)(mlx->param->posX + mlx->param->planeX * movespeed)][(int)mlx->param->posY] == 0)
			mlx->param->posX += mlx->param->planeX * movespeed;
		if (worldMap[(int)mlx->param->posX][(int)(mlx->param->posY + mlx->param->planeY * movespeed)] == 0)
			mlx->param->posY += mlx->param->planeY * movespeed;
	}	
	else if (keycode == KEY_LEFT)
	{
		double olddirX = mlx->param->dirX;
		mlx->param->dirX = mlx->param->dirX * cos(rotspeed) - mlx->param->dirY * sin(rotspeed);
		mlx->param->dirY = olddirX * sin(rotspeed) + mlx->param->dirY * cos(rotspeed);
		double oldplaneX = mlx->param->planeX;
		mlx->param->planeX = mlx->param->planeX * cos(rotspeed) - mlx->param->planeY * sin(rotspeed);
		mlx->param->planeY = oldplaneX * sin(rotspeed) + mlx->param->planeY * cos(rotspeed);
	}
	else if (keycode == KEY_RIGHT)
	{
		double olddirX = mlx->param->dirX;
		mlx->param->dirX = mlx->param->dirX * cos(-rotspeed) - mlx->param->dirY * sin(-rotspeed);
		mlx->param->dirY = olddirX * sin(-rotspeed) + mlx->param->dirY * cos(-rotspeed);
		double oldplaneX = mlx->param->planeX;
		mlx->param->planeX = mlx->param->planeX * cos(-rotspeed) - mlx->param->planeY * sin(-rotspeed);
		mlx->param->planeY = oldplaneX * sin(-rotspeed) + mlx->param->planeY * cos(-rotspeed);
	}
	else if (keycode == KEY_ESC)
		close(mlx);	
	return (0);
}

int	cub3d()
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->param = (t_param *)malloc(sizeof(t_param));
	mlx->img = (t_img *)malloc(sizeof(t_img));
	param_init(mlx);
	mlxs_init(mlx);
	imgs_init(mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 0, &key_press, mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_EXIT, 0, &close, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &rendering, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
