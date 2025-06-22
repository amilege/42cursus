/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:10:07 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/05 18:28:00 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"
#include <time.h>

int	calc_fractal(t_data *fractal, double x, double y)
{
	int	it_num;

	it_num = 0;
	if (fractal->name == MANDELBROT)
		it_num = mandelbrot(x, y);
	else if (fractal->name == JULIA)
		it_num = julia(fractal, x, y);
	else
		write(1, "Incorrecto\n", 11);
	return (it_num);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render(t_data *fractal)
{
	double	c_re;
	double	c_im;
	double	re_factor;
	double	im_factor;

	re_factor = (fractal->max_real - fractal->min_real) / (WIDTH - 1);
	im_factor = (fractal->max_imagi - fractal->min_imagi) / (HEIGHT - 1);
	mlx_clear_window(fractal->mlx, fractal->mlx_win);
	fractal->y = 0;
	while (fractal->y < HEIGHT)
	{
		c_im = fractal->max_imagi - fractal->y * im_factor;
		fractal->x = 0;
		while (fractal->x < WIDTH)
		{
			c_re = fractal->min_real + fractal->x * re_factor;
			fractal->it_num = calc_fractal(fractal, c_re, c_im);
			fractal->color = set_color(fractal->it_num);
			set_pixel_color(fractal, fractal->color);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img, 0, 0);
	return (0);
}
