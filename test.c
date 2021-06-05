
void	draw_line(t_mlx *mlx, int x_start)
{
	int y;
	
	y = -1;
	while (++y < mlx->param->lineHeight)
	{
		if (((mlx->param->y_start + y) * WIDTH + x_start) < WIDTH * HEIGHT)
		{
			if (mlx->param->side == 1)
			{
				if (mlx->param->stepY == 1)
					mlx->img->data[(mlx->param->y_start + y) * WIDTH + x_start] = 0xFF0000; //R
				else
					mlx->img->data[(mlx->param->y_start + y) * WIDTH + x_start] = 0x00FF00; //G
			}
			else
			{
				if (mlx->param->stepX == 1)
					mlx->img->data[(mlx->param->y_start + y) * WIDTH + x_start] = 0x0000FF; //B
				else
					mlx->img->data[(mlx->param->y_start + y) * WIDTH + x_start] = 0xFFFF00;
			}
		}
	}
}
