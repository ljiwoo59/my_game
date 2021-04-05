#include "cub3d.h"

void	read_file(char *s1)
{
	int fd;
	int byte;
	char c;
	char *text;

	if ((fd == open(s1, O_RDONLY)) < 0)
		return (1);
	else
	{
		byte = 0;
		while (read(fd, &c, 1) > 0)
			byte++;
		close(fd);
		if (!(text = (char *)malloc(byte + 1)))
			return (1);
		if ((fd == open(s1, O_RDONLY)) < 0)
			return (1);
		read(fd, text, byte);
		text[byte] = 0;
		close(fd);
	}
	return (0);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (read_file(argv[1]) == 1)
		{
			perror("Error\n"); // malloc fail, open fail
			return (0);
		}
//		cub3d();
		return (0);
	}
	else if (argc > 2 || argc < 2)
	{
		//if (argc > 2 && ft_strcmp(argv[1], "--save") == 0)
			// save bmp
		//else
		perror("Error\n"); //invalid argument
	}

	return (0);
}
