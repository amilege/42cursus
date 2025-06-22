/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:35:53 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/10 19:22:55 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"

int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	msg_error(t_data *fractal)
{
	write(1, "Parametros incorrectos, prueba:\n", 31);
	write(1, "\nMandelbrot\nJulia 0.11 -0.75\nJulia 0.285 -0.01\n", 47);
	write(1, "El Julia debe tener los parametros entre -2 y 2", 47);
	t_close(fractal);
	return (0);
}
