#include "cub3d.h"

static int		ft_wordcount(char const *s, char c)
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

static void		ft_strcpy(char *arr, char *start, char const *end)
{
	while (start < end)
	{
		*arr = *start;
		arr++;
		start++;
	}
	*arr = 0;
}

static char		**ft_free(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
	perror("Error\n"); //malloc fail
	exit(1);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	char	*start;
	int		i;

	if (!(arr = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
	{
		perror("Error\n"); //malloc fail
		exit(1);
	}
	i = 0;
	while (*s != "\n")
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s != c && *s)
				s++;
			if (!(arr[i] = (char *)malloc(s - start + 1)))
				ft_free(arr, i);
			ft_strcpy(arr[i++], start, s);
		}
		if (*s)
			s++;
	}
	arr[i] = 0;
	return (arr);
}
