#include "cub3d.h"

int		is_new_line(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		return_line(int index, int fd, char **line, char **saved)
{
	*line = ft_strldup(saved[fd], 0, index);
	saved[fd] = ft_strldup_file(saved[fd], index + 1, ft_strlen(saved[fd]));
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*saved[OPEN_MAX];
	char		buf[2];
	int			read_size;
	int			index;

	if (fd < 0 || line == 0)
		return (-1);
	if ((index = is_new_line(saved[fd])) != -1)
		return (return_line(index, fd, line, saved));
	while ((read_size = read(fd, buf, 1)) > 0)
	{
		buf[read_size] = 0;
		saved[fd] = ft_strjoin(saved[fd], buf);
		if ((index = is_new_line(saved[fd])) != -1)
			return (return_line(index, fd, line, saved));
	}
	if (read_size < 0)
		return (-1);
	if (saved[fd])
		*line = saved[fd];
	else
		*line = ft_strldup("", 0, 0);
	saved[fd] = 0;
	return (0);
}
