#include "cub3d.h"

void validation(char *str)
{
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!(*str))
			error();
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9')) 
			error();
		str++;
	}
}

int			ft_atoi(char *str)
{
	long long	num;
	int			minus;

	num = 0;
	minus = 1;	
	validation(str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	num *= minus;
	if (num > 2147483647 || num < -2147483648)
		error();
	return ((int)num);
}
