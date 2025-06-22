/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:47:29 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/09 10:24:41 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

int		ft_atoi(char *string);
size_t	ft_strlen(const char *c);
void	*ft_calloc(size_t count, size_t size);
void	intermedie(int *flag, int *len, char **string, int *octet);

#endif
