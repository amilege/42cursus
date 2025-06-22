/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:16:44 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/05 17:47:00 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"

int	mandelbrot(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	int		iteration;
	double	z_re2;

	z_re = c_re;
	z_im = c_im;
	iteration = 0;
	while (iteration < MAX_ITER)
	{
		if (z_re * z_re + z_im * z_im > (2 * 2))
			return (iteration);
		z_re2 = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re2;
		iteration = iteration + 1;
	}
	return (iteration);
}

int	julia(t_data *fractal, double z_re, double z_im)
{
	int		iteration;
	double	z_re2;

	iteration = 0;
	while (iteration < MAX_ITER)
	{
		if (z_re * z_re + z_im * z_im > (2 * 2))
			return (iteration);
		z_re2 = z_re * z_re - z_im * z_im + fractal->jc_re;
		z_im = 2 * z_re * z_im + fractal->jc_im;
		z_re = z_re2;
		iteration = iteration + 1;
	}
	return (iteration);
}
