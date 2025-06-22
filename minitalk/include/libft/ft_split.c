/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:51:51 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 12:57:53 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c);
static int	ft_len_words(char const *s, char c, int *end);
static void	ft_fill_up(char *super_array, int init, int end, char const *s);
static void	ft_free(char **super_array, int i);

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**super_array;
	int		end;
	int		init;

	end = 0;
	i = 0;
	super_array = (char **)ft_calloc((ft_count_words(s, c) + 1),
			sizeof(char *));
	if (!super_array)
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		init = ft_len_words(s, c, &end);
		super_array[i] = (char *)ft_calloc((end - init + 1), sizeof(char));
		if (super_array[i] == NULL)
		{
			ft_free(super_array, i);
			return (NULL);
		}
		ft_fill_up(super_array[i], init, (end - init), s);
		i++;
	}
	super_array[i] = NULL;
	return (super_array);
}

static void	ft_fill_up(char *super_array, int init, int end, char const *s)
{
	int	fill;

	fill = 0;
	while (fill < end)
	{
		super_array[fill] = s[init];
		fill++;
		init++;
	}
	super_array[fill] = '\0';
}

static void	ft_free(char **super_array, int i)
{
	while (i > 0)
	{
		free(super_array[i - 1]);
		i--;
	}
	free(super_array);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	whut;
	int	count;

	count = 0;
	whut = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (whut)
			{
				count++;
				whut = 0;
			}
		}
		else
			whut = 1;
		i++;
	}
	return (count);
}

static int	ft_len_words(char const *s, char c, int *end)
{
	int	start;
	int	whut;

	start = *end;
	whut = 1;
	while ((s[*end] != c || whut) && (*end < (int)ft_strlen(s)) && s[*end])
	{
		if (s[*end] != c)
			whut = 0;
		else if (s[*end] == c)
			start++;
		(*end)++;
	}
	return (start);
}
/*
int	main(void)
{
	int		i;
	char	*s;
	char	c;
	char	**test;

	i = 0;
	s = "Hello!";
	c = ' ';
	test = ft_split(s, c);
	while (i < ft_strlen(s))
	{
		printf("%s\n", test[i]);
		i++;
	}
	return (0);
}

//	printf("%s\n", **ft_split(s, c));
//	return (0);

//char **ft_split(char const *s, char c)
//	printf("%i", ft_count_words(s, c));
	printf("%i", ft_len_words(s, c, end));
	return (0);
}


	int start;
	int i;
	i = 0;

	start = *end;
	while (s[i]
	while (s[i] == c)
	{
		printf("len:separador %d %d %d \n", start, end ,i);
		i++;
		if (s[i] == '\0')
			return (start);
	}
	start = i;
	while (s[i] != c && s[i] != '\0')
	{
		printf("len:no separador %d %d %d \n", start, end, i);
		end++;
		i++;
	}
	return (start);
}
*/
