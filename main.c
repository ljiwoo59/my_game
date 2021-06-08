#include "cub3d.h"

int ft_sstrlen(char **s)
{
	int count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}

int  color_set(char *code)
{
	char **code_arr;
	int rgb_arr[3];
	int i;

	code_arr = ft_split(code, ',');
	if (ft_sstrlen(code_arr) != 3)
		error();
	i = -1;
	while (++i < 3)
	{
		if (ft_atoi(code_arr[i]) >= 0 && ft_atoi(code_arr[i]) <= 255)
			rgb_arr[i] = ft_atoi(code_arr[i]);
		else
			error();
	}
	i = -1;
	while (++i < 3)
		free(code_arr[i]);
	free(code_arr);
	return (rgb_arr[0] << 16 | rgb_arr[1] << 8 | rgb_arr[2]);
}

int set_info(t_info *info, char *line)
{
	char **line_arr;
	int i;

	line_arr = ft_split(line, ' ');
	if (ft_sstrlen(line_arr) != 2)
		error();
	if (ft_strcmp("NO", line_arr[0]))
		info->path_no = ft_strdup(line_arr[1]);
	else if (ft_strcmp("SO", line_arr[0]))
		info->path_so = ft_strdup(line_arr[1]);
	else if (ft_strcmp("WE", line_arr[0]))
		info->path_we = ft_strdup(line_arr[1]);
	else if (ft_strcmp("EA", line_arr[0]))
		info->path_ea = ft_strdup(line_arr[1]);
	else if (ft_strcmp("F", line_arr[0]))
		info->rgb_f = color_set(line_arr[1]);
	else if (ft_strcmp("C", line_arr[0]))
		info->rgb_c = color_set(line_arr[1]);
	else
		error();
	i = 0;
	while (i < 2)
		free(line_arr[i++]);
	free(line_arr);
	return (1);
}

char *ft_append(char *map, char c)
{
	int size;
	int i;
	char *new_map;

	size = ft_strlen(map);
	if (!(new_map = (char *)malloc(size + 2)))
		error();
	i = -1;
	while (++i < size)
		new_map[i] = map[i];
	new_map[i++] = c;
	new_map[i] = 0;
	free(map);
	return (new_map);
}

int valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

void check_wall(char **map_arr, int col, int row)
{
	if (row == 0 || row == (ft_sstrlen(map_arr) - 1) || col == 0 ||  (col == (ft_strlen(map_arr[row]) - 1)))
		error();
	if (col > ft_strlen(map_arr[row - 1]) || col > ft_strlen(map_arr[row + 1]) || (col + 1) > ft_strlen(map_arr[row]) || (col - 1) < 0)
		error();
	if (map_arr[row - 1][col] == ' ' || map_arr[row + 1][col] == ' ' || map_arr[row][col - 1] == ' ' || map_arr[row][col + 1] == ' ')
		error();
}

int check_position(t_info *info, char **map_arr, int col, int row)
{
	if (info->pos_flag != 0)
		error();
	check_wall(map_arr, col, row);
	info->init_posX = col;
	info->init_posY = row;
	if (map_arr[row][col] == 'N')
	{
		info->init_dirX = 0;
		info->init_dirY = 1;
	}
	else if (map_arr[row][col] == 'S')
	{
		info->init_dirX = 0;
		info->init_dirY = -1;
	}
	else if (map_arr[row][col] == 'E')
	{
		info->init_dirX = 1;
		info->init_dirY = 0;
	}
	else if (map_arr[row][col] == 'W')
	{
		info->init_dirX = -1;
		info->init_dirY = 0;
	}
	return (1);
}

void map_set(char *map, t_info *info)
{
	char **map_arr;
	int col;
	int row;

	map_arr = ft_split(map, '\n');
	info->pos_flag = 0;
	row = -1;
	while (++row < ft_sstrlen(map_arr))
	{
		col = -1;
		while (++col < ft_strlen(map_arr[row]))
		{
			if (map_arr[row][col] == '0')
				check_wall(map_arr, col, row);
			else if (map_arr[row][col] == 'N' || map_arr[row][col] == 'S' || map_arr[row][col] == 'E' || map_arr[row][col] == 'W')
				info->pos_flag = check_position(info, map_arr, col, row);
		}
	}
	if (info->pos_flag == 0)
		error();
	info->map = map_arr;
}

void read_map(int fd, t_info *info)
{
	char *map;
	int i;
	char c;

	if (!(map = (char *)malloc(1)))
		error();
	map = 0;
	while (read(fd, &c, 1) > 0)
		map = ft_append(map, c);
	close(fd);
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
	map_set(map, info);
}

void read_file(char *file, t_info *info)
{
	int fd;
	char *line;
	int flag;

	flag = 0;
	if (!(fd = open(file, O_RDONLY)))
		error();
	while (flag != 6 && get_next_line(fd, &line))
	{
		if (ft_strcmp("", line) == 0)
			flag += set_info(info, line);
		free(line);
	}
	read_map(fd, info);
	
	for (int i = 0; i < ft_sstrlen(info->map); i++)
		printf("%s\n", info->map[i]);
	printf("%d\n", info->init_posX);
	printf("%d\n", info->init_posY);
	printf("%d\n", info->init_dirX);
	printf("%d\n", info->init_dirY);

}

int main(int argc, char *argv[])
{
	t_info info;

	if (argc != 2)
		error();
	read_file(argv[1], &info);
	pause();
	return (0);
}
