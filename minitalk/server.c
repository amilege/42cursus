/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:40:19 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/09 10:27:23 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "include/printf/ft_printf.h"

void	rest(char **string, int *len, int *flag)
{
	ft_printf("%s\n",*string);
	free(*string);
	*string = NULL;
	*len = 0;
	*flag = 0;
}

void	fill(int *len, int *flag, char **string, int *octet)
{
	if ((*string)[*len] == '\0')
		rest(string, len, flag);
	else
		*len += 1;
	*octet = 0;
}

void	intermedie(int *flag, int *len, char **string, int *octet)
{
	*string = ft_calloc((*len + 1), sizeof(char));
	if (!*string)
		return ;
	(*string)[*len] = '\0';
	*flag = 1;
	*len = 0;
	*octet = 0;
}

void	controlbit(int sin)
{
	static int	flag = 0;
	static int	octet = 0;
	static int	len = 0;
	static char	*string;

	if (flag == 0)
	{
		if (sin == SIGUSR1)
			len |= (1 << octet);
		octet++;
		if (octet == 32)
			intermedie(&flag, &len, &string, &octet);
	}
	else
	{
		if (sin == SIGUSR1)
			string[len] = (string[len] | (1 << octet));
		octet++;
		if (octet == 8)
			fill(&len, &flag, &string, &octet);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%i\n", pid);
	signal(SIGUSR1, controlbit);
	signal(SIGUSR2, controlbit);
	while (1)
	{
		sleep(80);
	}
	return (0);
}
