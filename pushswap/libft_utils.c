/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:40:38 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/01 18:48:00 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(char *a)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (a[i] == '\t' || a[i] == '\n' || a[i] == '\v' || a[i] == '\f'
		|| a[i] == '\f' || a[i] == ' ')
		i++;
	if (a[i] == '-' || a[i] == '+')
	{
		if (a[i] == '-')
			sign *= -1;
		i++;
	}
	if (a[i] == '-' || a[i] == '+')
		error();
	while (a[i] >= '0' && a[i] <= '9')
		num = (num * 10) + a[i++] - '0';
	if ((int)num * sign < 0 != sign < 0)
		error();
	return (num * sign);
}

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_atol(char *a)
{
	int			i;
	int			sign;
	long		num;

	i = 0;
	sign = 1;
	num = 0;
	while (a[i] == '\t' || a[i] == '\n' || a[i] == '\v' || a[i] == '\f'
		|| a[i] == '\f' || a[i] == ' ')
		i++;
	if (a[i] == '-' || a[i] == '+')
	{
		if (a[i] == '-')
			sign *= -1;
		i++;
	}
	if (a[i] == '-' || a[i] == '+')
		error();
	while (a[i] >= '0' && a[i] <= '9')
		num = (num * 10) + a[i++] - '0';
	if ((int)num * sign < 0 != sign < 0)
		error();
	return (num * sign);
}

int	lim_int(char *argv)
{
	long	num;

	num = ft_atol(argv);
	if (num > 2147483647)
		error();
	return (0);
}
