#include "cub3d.h"

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
