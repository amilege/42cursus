/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:40:21 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/10 19:17:02 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"
//#include <stdlib.h>
//#include <time.h>
//#include <unistd.h>

int	t_close(t_data *f)
{
	mlx_destroy_window(f->mlx, f->mlx_win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_data	fractal;

	if (argc < 2)
	{
		write(1, "Parametros incorrectos, prueba:\n", 31);
		write(1, "\nMandelbrot\nJulia 0.11 -0.75\nJulia 0.285 -0.01", 46);
		return (0);
	}
	fractal.mlx = mlx_init();
	fractal.mlx_win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "FRACTOL");
	if (!fractal.mlx_win)
		exit(EXIT_FAILURE);
	fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
	if (!fractal.img)
	{
		mlx_destroy_window(fractal.mlx_win, fractal.mlx_win);
		exit(EXIT_FAILURE);
	}
	fractal.addr = mlx_get_data_addr(fractal.img, &bits_per_pixel, &line_length,
			&endian);
	init_hook(&fractal, argv, argc);
	return (0);
}
