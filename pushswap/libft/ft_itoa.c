/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:11:47 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 13:15:38 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_len(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*a_char;

	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	a_char = ft_calloc((len + 1), sizeof(char));
	if (a_char == NULL)
		return (NULL);
	if (n == 0)
		a_char[0] = '0';
	if (n < 0)
	{
		a_char[0] = '-';
		n *= -1;
	}
	while (n)
	{
		len--;
		a_char[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (a_char);
}
/*
int	main(void)
{
	int		num;
	char	*str;

	num = -2147483648;
	str = ft_itoa(num);
	printf("El resultado final es: %s", str);
	return (0);
}
*/
