#include "cub3d.h"

int		valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

void	read_map(int fd, t_mlx *mlx)
{
	char	*map;
	int		i;
	char	c;

	if (!(map = (char *)malloc(1)))
		error();
	map[0] = 0;
	while (read(fd, &c, 1) > 0)
		map = ft_append(map, c);
	i = 0;
	while (map[i] == '\n')
		i++;
	while (i < ft_strlen(map))
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			error();
		if (!(valid_char(map[i])))
			error();
		i++;
	}
	map_set(map, mlx);
}

void	read_file(char *file, t_mlx *mlx)
{
	int		fd;
	char	*line;
	int		flag;

	flag = 0;
	if (!(fd = open(file, O_RDONLY)))
		error();
	while (flag != 6 && get_next_line(fd, &line))
	{
		if (ft_strcmp("", line) == 0)
			flag += set_info(mlx, line);
		free(line);
	}
	read_map(fd, mlx);
	close(fd);
}

int		main(int argc, char *argv[])
{
	t_mlx *mlx;

	if (argc != 2)
		error();
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		error();
	if (!(mlx->info = (t_info *)malloc(sizeof(t_info))))
		error();
	read_file(argv[1], mlx);
//	cub3d(mlx);
	ft_close(mlx);
	return (0);
}
