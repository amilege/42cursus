/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:04:10 by amile-ge          #+#    #+#             */
/*   Updated: 2024/10/13 18:22:58 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_num(char *argv)
{
	int	i;
	int	last;

	last = 0;
	i = 0;
	last = ft_strlen(argv);
	if (last > 11)
		return (1);
	ft_atol(argv);
	last -= 1;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[last - i] != 0)
	{
		if (!(argv[i] >= '0' && argv[i] <= '9') && !(argv[i] == 32))
		{
			printf("Parameters must contain only numbers");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	meals;

	i = 1;
	if (argc == 6)
	{
		meals = atoi(argv[5]);
		if (meals <= 0)
		{
			printf("Number of meals must be greater than 0.");
			return (1);
		}
	}
	while (i < argc)
	{
		if (ft_num(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
