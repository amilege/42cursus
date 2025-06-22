/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:57:43 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/05 18:00:05 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"

int	set_color(int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == MAX_ITER)
	{
		r = 0;
		g = 0;
		b = 0;
	}
	else
	{
		r = (int)(sin(0.1 * iter + 1) * 127 + 128);
		g = (int)(sin(0.2 * iter + 2) * 127 + 128);
		b = (int)(sin(0.4 * iter + 4) * 127 + 128);
	}
	return (((r << 16) | (g << 8) | (b)));
}

void	set_pixel_color(t_data *fractal, int color)
{
	int	pos;

	pos = (fractal->y * WIDTH + fractal->x) * 4;
	fractal->addr[pos] = (color & 0xFF0000) >> 16;
	fractal->addr[pos + 1] = (color & 0x00FF00) >> 8;
	fractal->addr[pos + 2] = color & 0x0000FF;
}
