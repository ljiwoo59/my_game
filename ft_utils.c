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

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if (!(ptr = (char *)malloc(len + 1)))
		error();
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

void	ft_free(char **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}
