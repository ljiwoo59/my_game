#include "cub3d.h"

void	error2(int i)
{
	printf("%s %d\n", "Error", i);
	exit(0);
}

void	error(void)
{
	printf("%s\n", "Error");
	exit(0);
}

void	sub_texture_init(t_mlx *mlx)
{
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
					mlx->info->path_no, &(mlx->img->width),
					&(mlx->img->height))))
		error();
	if (!(mlx->img->texture = (int *)mlx_get_data_addr(mlx->img->t_ptr,
					&mlx->img->t_bpp, &mlx->img->t_size_l,
					&mlx->img->t_endian)))
		error();
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
					mlx->info->path_so, &(mlx->img->width),
					&(mlx->img->height))))
		error();
	if (!(mlx->img->texture2 = (int *)mlx_get_data_addr(mlx->img->t_ptr,
					&mlx->img->t_bpp, &mlx->img->t_size_l,
					&mlx->img->t_endian)))
		error();
}

void	texture_init(t_mlx *mlx)
{
	sub_texture_init(mlx);
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
					mlx->info->path_we, &(mlx->img->width),
					&(mlx->img->height))))
		error();
	if (!(mlx->img->texture3 = (int *)mlx_get_data_addr(mlx->img->t_ptr,
					&mlx->img->t_bpp, &mlx->img->t_size_l,
					&mlx->img->t_endian)))
		error();
	if (!(mlx->img->t_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
					mlx->info->path_ea, &(mlx->img->width),
					&(mlx->img->height))))
		error();
	if (!(mlx->img->texture4 = (int *)mlx_get_data_addr(mlx->img->t_ptr,
					&mlx->img->t_bpp, &mlx->img->t_size_l,
					&mlx->img->t_endian)))
		error();
}
