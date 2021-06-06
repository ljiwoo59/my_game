#include "cub3d.h"
int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	_close(t_mlx *mlx)
{
	free(mlx->param);
	free(mlx->img);
	free(mlx);
	pause();
	exit(0);
}

void	wall_color(t_mlx *mlx, int y, int x_start)
{
	int pos;

	pos = y * WIDTH + x_start;
	mlx->param->texY = (int)mlx->param->texPos;
	mlx->param->texPos += mlx->param->step;
	if (mlx->param->side == 1)
	{
		if (mlx->param->stepY == 1)
			mlx->img->data[pos] = mlx->img->texture[mlx->param->texY * mlx->img->height + mlx->param->texX]; //R East
		else
			mlx->img->data[pos] = mlx->img->texture2[mlx->param->texY * mlx->img->height + mlx->param->texX]; //west
	}
	else
	{
		if (mlx->param->stepX == 1)
			mlx->img->data[pos] = mlx->img->texture3[mlx->param->texY * mlx->img->height + mlx->param->texX]; //south
		else
			mlx->img->data[pos] = mlx->img->texture4[mlx->param->texY * mlx->img->height + mlx->param->texX]; //north
	}
}

void	draw_line(t_mlx *mlx, int x_start)
{
	int y;
	
	y = -1;
	while (++y < HEIGHT)
	{
		if (y < mlx->param->y_start)
			mlx->img->data[(y * WIDTH + x_start)] = 0xC0FFFF;
		else if (y > mlx->param->y_end)
			mlx->img->data[(y * WIDTH + x_start)] = 0xFFE4E1;
		else
			wall_color(mlx, y, x_start);
	}
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
	if (worldMap[mlx->param->mapX][mlx->param->mapY] > 0)
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

void	error()
{
	write(2, "Error\n", 6);
	exit(0);
}

void	program_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		error();
	if (!(mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub3d")))
		error();
	mlx->param->posX = 22;
	mlx->param->posY = 12;
	mlx->param->dirX = -1;
	mlx->param->dirY = 0;
	mlx->param->planeX = 0;
	mlx->param->planeY = 0.66;
	mlx->param->movespeed = 0.5;
	mlx->param->rotspeed = 0.33;
}

void	imgs_init(t_mlx *mlx)
{
	if (!(mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT)))
		error();
	if (!(mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp, &mlx->img->size_l, &mlx->img->endian)))
		error();
}

void	texture_init(t_mlx *mlx)
{
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./pics/eagle.xpm", &(mlx->img->width), &(mlx->img->height))))
		error();
	if (!(mlx->img->texture = (int *)mlx_get_data_addr(mlx->img->t_ptr, &mlx->img->t_bpp, &mlx->img->t_size_l, &mlx->img->t_endian)))
		error();
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./pics/redbrick.xpm", &(mlx->img->width), &(mlx->img->height))))
		error();
	if (!(mlx->img->texture2 = (int *)mlx_get_data_addr(mlx->img->t_ptr, &mlx->img->t_bpp, &mlx->img->t_size_l, &mlx->img->t_endian)))
		error();
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./pics/bluestone.xpm", &(mlx->img->width), &(mlx->img->height))))
		error();
	if (!(mlx->img->texture3 = (int *)mlx_get_data_addr(mlx->img->t_ptr, &mlx->img->t_bpp, &mlx->img->t_size_l, &mlx->img->t_endian)))
		error();
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./pics/wood.xpm", &(mlx->img->width), &(mlx->img->height))))
		error();
	if (!(mlx->img->texture4 = (int *)mlx_get_data_addr(mlx->img->t_ptr, &mlx->img->t_bpp, &mlx->img->t_size_l, &mlx->img->t_endian)))
		error();
}

int	main()
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		error();
	if (!(mlx->param = (t_param *)malloc(sizeof(t_param))))
		error();
	if (!(mlx->img = (t_img *)malloc(sizeof(t_img))))
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
