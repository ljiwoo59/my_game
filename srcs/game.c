#include "cub3d.h"

void	r_param_set2(t_mlx *mlx)
{
	mlx->param->wall_x -= floor(mlx->param->wall_x);
	mlx->param->tex_x = mlx->param->wall_x * (double)(mlx->img->width);
	mlx->param->step = 1.0 * mlx->img->height / mlx->param->line_height;
	mlx->param->tex_pos =
		(mlx->param->y_start - HEIGHT / 2 + mlx->param->line_height / 2)
		* mlx->param->step;
}

void	r_param_set(t_mlx *mlx, int x)
{
	if (mlx->param->side == 0)
	{
		mlx->param->perp_wall_dist = (mlx->param->map_x - mlx->param->pos_x +
				(1 - mlx->param->step_x) / 2) / mlx->param->ray_dir_x;
		mlx->param->wall_x = mlx->param->pos_y +
			mlx->param->perp_wall_dist * mlx->param->ray_dir_y;
	}
	else
	{
		mlx->param->perp_wall_dist = (mlx->param->map_y - mlx->param->pos_y +
				(1 - mlx->param->step_y) / 2) / mlx->param->ray_dir_y;
		mlx->param->wall_x = mlx->param->pos_x +
			mlx->param->perp_wall_dist * mlx->param->ray_dir_x;
	}
	mlx->param->line_height = (int)(HEIGHT / mlx->param->perp_wall_dist);
	mlx->param->y_start = -mlx->param->line_height / 2 + HEIGHT / 2;
	if (mlx->param->y_start < 0)
		mlx->param->y_start = 0;
	mlx->param->y_end = mlx->param->line_height / 2 + HEIGHT / 2;
	if (mlx->param->y_end >= HEIGHT)
		mlx->param->y_end = HEIGHT - 1;
	r_param_set2(mlx);
	draw_line(mlx, x);
}

void	dda_set(t_mlx *mlx)
{
	if (mlx->param->side_dist_x < mlx->param->side_dist_y)
	{
		mlx->param->side_dist_x += mlx->param->delta_dist_x;
		mlx->param->map_x += mlx->param->step_x;
		mlx->param->side = 0;
	}
	else
	{
		mlx->param->side_dist_y += mlx->param->delta_dist_y;
		mlx->param->map_y += mlx->param->step_y;
		mlx->param->side = 1;
	}
	if (mlx->info->map[mlx->param->map_y][mlx->param->map_x] == '1')
		mlx->param->hit = 1;
}

int		rendering(t_mlx *mlx)
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

int		cub3d(t_mlx *mlx)
{
	if (!(mlx->param = (t_param *)malloc(sizeof(t_param))))
		error();
	if (!(mlx->img = (t_img *)malloc(sizeof(t_img))))
		error();
	if (!(mlx->mlx_ptr = mlx_init()))
		error();
	if (!(mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub3d")))
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
