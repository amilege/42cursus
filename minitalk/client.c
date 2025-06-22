/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:37:29 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/09 10:23:20 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "include/printf/ft_printf.h"

void	sendlen(int pid, int len)
{
	int	octet;

	octet = 0;
	while (octet < 32)
	{
		if (((len >> octet) & 1) == 1)
			kill(pid, SIGUSR1);
		else if (((len >> octet) & 1) == 0)
			kill(pid, SIGUSR2);
		usleep(80);
		octet++;
	}
}

void	sendbits(int pid, char *string, int len)
{
	int	i;
	int	octet;

	i = 0;
	if (kill(pid, 0) < 0)
	{
		ft_printf("ERROR : cant send sig to pid : %d\n", pid);
		exit(EXIT_FAILURE);
	}
	while (i <= len)
	{
		octet = 0;
		while (octet < 8)
		{
			if (((string[i] >> octet) & 1) == 1)
				kill(pid, SIGUSR1);
			else if (((string[i] >> octet) & 1) == 0)
				kill(pid, SIGUSR2);
			usleep(80);
			octet++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	len;
	int	pid;

	if (argc < 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (!pid || pid < 0)
	{
		ft_printf("El pid no es correcto");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[2]);
	sendlen(pid, len);
	sendbits(pid, argv[2], len);
}
