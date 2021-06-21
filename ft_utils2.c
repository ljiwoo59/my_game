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

int		ft_wordcount(char *s, char c)
{
	int count;
	int word;

	count = 0;
	word = 0;
	while (*s)
	{
		if ((*s != c) && !word)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

void		ft_strcpy(char *arr, char *start, char *end)
{
	while (start < end)
	{
		*arr = *start;
		arr++;
		start++;
	}
	*arr = 0;
}

char			**ft_split(char *s, char c)
{
	char	**arr;
	char	*start;
	int		i;

	if (!(arr = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		error();
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s != c && *s)
				s++;
			if (!(arr[i] = (char *)malloc(s - start + 1)))
				error();
			ft_strcpy(arr[i++], start, s);
		}
		if (*s)
			s++;
	}
	arr[i] = 0;
	return (arr);
}
