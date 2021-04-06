#include "cub3d.h"

char	*read_file(char *s1)
{
	int fd;
	int byte;
	char c;
	char *text;

	if ((fd == open(s1, O_RDONLY)) < 0)
		return (0);
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
	return (text);
}

int	only_digit(char *s1)
{
	while (*s1)
	{
		if (*s1 < 48 || *s1 > 57)
			return (0);
		s1++;
	}
	return (1);
}

int	ft_sstrlen(char **s1)
{
	count = 0;
	while (*s1)
	{
		count++;
		s1++;
	}	
	return (count);
}

void	check(char *s1, t_info *info)
{
	int all;
	int i;
	char	**temp;

	all = 8; // element num
	i = 0;
	while (all)
	{
		if (ft_strncmp(s1 + i, "R ", 2))
		{
			temp = ft_split(s1 + i, " ");
			if (ft_sstrlen(temp) == 3 && (only_digit(temp[1]) && only_digit(temp[2])))
			{
				info->render_x = ft_atoi(ft_strdup(temp[1]));
				info->render_y = ft_atoi(ft_strdup(temp[2]));
				all--;
			}
			else
			{
				perror("Error\n"); //wrong R
				exit(1);
			}
			free(temp);
		}
		else if (ft_strncmp(s1 + i, "NO ", 3))
		{
			temp = ft_split(s1 + i, " ");
			if (ft_sstrlen(temp) == 2)
			{
				info->path_n = ft_strdup(temp[1]);
				all--;
			}
			else
			{
				perror("Error\n"); //wrong NO
				exit(1);
			}
			free(temp);
		}

		else if (ft_strncmp(s1 + i, "SO ", 3))
		{
			temp = ft_split(s1 + i, " ");
			if (ft_sstrlen(temp) == 2)
			{
				info->path_n = ft_strdup(temp[1]);
				all--;
			}
			else
			{
				perror("Error\n"); //wrong SO
				exit(1);
			}
			free(temp);
		}
		else if (ft_strncmp(s1 + i, "WE ", 3))
		{
			temp = ft_split(s1 + i, " ");
			if (ft_sstrlen(temp) == 2)
			{
				info->path_n = ft_strdup(temp[1]);
				all--;
			}
			else
			{
				perror("Error\n"); //wrong WE
				exit(1);
			}
			free(temp);
		}
		else if (ft_strncmp(s1 + i, "EA ", 3))
		{
			temp = ft_split(s1 + i, " ");
			if (ft_sstrlen(temp) == 2)
			{
				info->path_n = ft_strdup(temp[1]);
				all--;
			}
			else
			{
				perror("Error\n"); //wrong EA
				exit(1);
			}
			free(temp);
		}
		else if (ft_strncmp(s1 + i, "S ", 2))
		{
			temp = ft_split(s1 + i, " ");
			if (ft_sstrlen(temp) == 2)
			{
				info->path_n = ft_strdup(temp[1]);
				all--;
			}
			else
			{
				perror("Error\n"); //wrong S
				exit(1);
			}
			free(temp);
		}
		else if (ft_strncmp(s1 + i, "F ", 2))
		{
			temp = ft_split(s1 + i, " ");
			if (ft_sstrlen(temp) == 2)
			{
				info->path_n = ft_strdup(temp[1]);
				all--;
			}
			else
			{
				perror("Error\n"); //wrong F
				exit(1);
			}
			free(temp);
		}
		else if (ft_strncmp(s1 + i, "C ", 2))
		{
			temp = ft_split(s1 + i, " ");
			if (ft_sstrlen(temp) == 2)
			{
				info->path_n = ft_strdup(temp[1]);
				all--;
			}
			else
			{
				perror("Error\n"); //wrong C
				exit(1);
			}
			free(temp);
		}
		else if (s1[i] == "\n")
			i++;
		else
		{
			perror("Error\n"); //not enough info
			exit(1);
		}
		while (s1[i] != "\n")
			i++;
	}
	//check map
}

int ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	char	*text;
	t_info *info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
	{
		perror("Error\n");
		return (0);
	}
	if (argc == 2)
	{
		if (!(text = read_file(argv[1])))
		{
			perror("Error\n"); // malloc fail, open fail
			return (0);
		}
		check(text, info);
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
	free(text);
	free(info);
	return (0);
}
