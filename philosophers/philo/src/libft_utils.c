/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:40:38 by amile-ge          #+#    #+#             */
/*   Updated: 2024/09/25 12:10:34 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
		return (-1);
	while (a[i] >= '0' && a[i] <= '9')
		num = (num * 10) + a[i++] - '0';
	if (((int)num * sign < 0) != (sign < 0))
		return (-1);
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
	int		i;
	int		sign;
	long	num;

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
		return (-1);
	while (a[i] >= '0' && a[i] <= '9')
		num = (num * 10) + a[i++] - '0';
	if (((int)num * sign < 0) != (sign < 0))
		return (-1);
	return (num * sign);
}

int	lim_int(char *argv)
{
	long	num;

	num = ft_atol(argv);
	if (num > 2147483647 || num == -1)
	{
		return (1);
	}
	printf("be");
	return (0);
}
