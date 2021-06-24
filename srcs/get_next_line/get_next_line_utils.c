#include "cub3d.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strldup(char *s1, int start, int end)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char *)malloc(end - start + 1)))
		error();
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strldup_file(char *s1, int start, int end)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char *)malloc(end - start + 1)))
		error();
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = 0;
	if (s1)
		free(s1);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		size;
	int		i;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(arr = (char *)malloc(size + 1)))
		error();
	i = 0;
	while (s1 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (*s2)
		arr[i++] = *s2++;
	arr[i] = 0;
	if (s1)
		free(s1);
	return (arr);
}
