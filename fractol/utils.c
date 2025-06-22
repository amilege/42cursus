/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:03:22 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/10 19:26:59 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"

int	num(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	else if (!isdigit(str[i]))
		return (0);
	while (isdigit(str[i]) || str[i] == '.')
	{
		if (flag == 0 && str[i] == '.')
			flag = 1;
		else if (str[i] == '.' && flag == 1)
			return (0);
		i++;
	}
	if (!isdigit(str[i]) && str[i] != '\0')
		return (0);
	return (1);
}

void	*ft_bzero(void *str, int size)
{
	unsigned char	*str_str;
	int				i;

	str_str = (unsigned char *)str;
	i = 0;
	while (i < size)
	{
		*str_str = '\0';
		str_str++;
		i++;
	}
	return (str);
}

void	*ft_calloc(int count, int size)
{
	void	*memory;

	memory = malloc(size * count);
	if (memory == 0)
		return (0);
	ft_bzero(memory, (size * count));
	return (memory);
}

double	ft_atoi(char *str)
{
	int		i;
	int		sign;
	double	x;

	x = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = (x * 10) + str[i] - '0';
		i++;
	}
	if (str[i++] == '.')
		x = decimals(x, str, i, sign);
	return (x);
}

double	decimals(double x, char *str, int i, int sign)
{
	int		decimals;
	double	res;

	decimals = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = (x * 10) + str[i] - '0';
		i++;
		decimals++;
	}
	while (decimals != 0)
	{
		x /= 10;
		decimals--;
	}
	res = x * sign;
	return (x * sign);
}
