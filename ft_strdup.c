#include "cub3d.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if (!(ptr = (char *)malloc(len + 1)))
	{
		perror("Error\n");
		exit(1);
	}
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
