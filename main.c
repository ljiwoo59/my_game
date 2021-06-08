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
	printf("%s %d\n", "return", rgb_arr[0]);
	return (rgb_arr[0]);
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

void read_file(char *file, t_info *info)
{
	int fd;
	char *line;
	int flag;

	flag = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (ft_strcmp("", line) == 0 && flag != 6)
			flag += set_info(info, line);
//		if (flag == 6 && ft_strcmp("", line) == 0)
		free(line);
	}
	printf("%d\n", info->rgb_f);
	printf("%d\n", info->rgb_c);
	printf("%s\n", info->path_so);
}

int main(int argc, char *argv[])
{
	t_info *info;

	if (argc != 2)
		error();
	if (!(info = (t_info *)malloc(sizeof(info))))
		error();
	read_file(argv[1], info);
	return (0);
}
