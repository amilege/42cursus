/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:45:43 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 13:21:12 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	x;

	x = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
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
	return (x * sign);
}
/*
int	main(void)
{
	char	*str;

  str = "49593904";
  printf("%i", ft_atoi(str));
  return (0);
}

int	main(int argc, char **argv)
{
  if (argc == 2)
	printf("%i", ft_atoi(argv[1]));
  return (0);
}
*/
