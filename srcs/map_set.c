#include "cub3d.h"

int		color_set(char *code)
{
	char	**code_arr;
	int		rgb_arr[3];
	int		i;

	code_arr = ft_split(code, ',');
	if (ft_sstrlen(code_arr) != 3)
		error();
	i = -1;
	while (code_arr[++i])
	{
		if (ft_atoi(code_arr[i]) >= 0 && ft_atoi(code_arr[i]) <= 255)
			rgb_arr[i] = ft_atoi(code_arr[i]);
		else
			error();
	}
	i = -1;
	while (code_arr[++i])
		free(code_arr[i]);
	free(code_arr);
	return (rgb_arr[0] << 16 | rgb_arr[1] << 8 | rgb_arr[2]);
}

int		set_info(t_mlx *mlx, char *line)
{
	char **line_arr;

	line_arr = ft_split(line, ' ');
	if (ft_sstrlen(line_arr) != 2)
		error();
	if (ft_strcmp("NO", line_arr[0]))
		mlx->info->path_no = ft_strdup(line_arr[1]);
	else if (ft_strcmp("SO", line_arr[0]))
		mlx->info->path_so = ft_strdup(line_arr[1]);
	else if (ft_strcmp("WE", line_arr[0]))
		mlx->info->path_we = ft_strdup(line_arr[1]);
	else if (ft_strcmp("EA", line_arr[0]))
		mlx->info->path_ea = ft_strdup(line_arr[1]);
	else if (ft_strcmp("F", line_arr[0]))
		mlx->info->rgb_f = color_set(line_arr[1]);
	else if (ft_strcmp("C", line_arr[0]))
		mlx->info->rgb_c = color_set(line_arr[1]);
	else
		error();
	ft_free(line_arr, 2);
	return (1);
}

void	map_set(char *map, t_mlx *mlx)
{
	char	**map_arr;
	int		col;
	int		row;

	map_arr = ft_split(map, '\n');
	mlx->info->pos_flag = 0;
	row = -1;
	while (++row < ft_sstrlen(map_arr))
	{
		col = -1;
		while (++col < ft_strlen(map_arr[row]))
		{
			if (map_arr[row][col] == '0')
				check_wall(map_arr, col, row);
			else if (map_arr[row][col] == 'N' || map_arr[row][col] == 'S'
					|| map_arr[row][col] == 'E' || map_arr[row][col] == 'W')
				mlx->info->pos_flag = check_position(mlx, map_arr, col, row);
		}
	}
	if (mlx->info->pos_flag == 0)
		error();
	mlx->info->map = map_arr;
	map_arr = NULL;
	free(map);
}

void	check_wall(char **map_arr, int col, int row)
{
	if (row == 0 || row == (ft_sstrlen(map_arr) - 1)
			|| col == 0 || (col == (ft_strlen(map_arr[row]) - 1)))
		error();
	if (col > ft_strlen(map_arr[row - 1]) || col > ft_strlen(map_arr[row + 1])
			|| (col + 1) > ft_strlen(map_arr[row]) || (col - 1) < 0)
		error();
	if (map_arr[row - 1][col] == ' ' || map_arr[row + 1][col] == ' '
			|| map_arr[row][col - 1] == ' ' || map_arr[row][col + 1] == ' ')
		error();
}

int		check_position(t_mlx *mlx, char **map_arr, int col, int row)
{
	if (mlx->info->pos_flag != 0)
		error();
	check_wall(map_arr, col, row);
	mlx->info->init_pos_x = (double)col + 0.5;
	mlx->info->init_pos_y = (double)row + 0.5;
	if (map_arr[row][col] == 'N')
		dir_set(mlx, 1);
	else if (map_arr[row][col] == 'S')
		dir_set(mlx, 2);
	else if (map_arr[row][col] == 'E')
		dir_set(mlx, 3);
	else if (map_arr[row][col] == 'W')
		dir_set(mlx, 4);
	return (1);
}
