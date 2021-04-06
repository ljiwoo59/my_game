#include "cub3d.h"

int			ft_atoi(const char *str)
{
	long long	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (num > 2147483647)
		num = 2147483647;
	free(str);
	return ((int)num);
}
