/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:43:24 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/10 19:22:08 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"
#include "mlx/mlx.h"

void	clean_all(t_data *fractal)
{
	fractal->min_real = 0;
	fractal->max_real = 0;
	fractal->min_imagi = 0;
	fractal->max_imagi = 0;
	fractal->x = 0;
	fractal->y = 0;
}

int	type_cmp(char *nom, char *compar)
{
	int	i;

	i = 0;
	while (nom[i] != '\0')
	{
		if (nom[i] != compar[i])
			return (0);
		i++;
	}
	return (1);
}

void	set_fractal(t_data *f, char **argv, int argc)
{
	if (type_cmp(argv[1], "Mandelbrot"))
	{
		f->name = MANDELBROT;
		if (argc > 2)
		{
			write(1, "Mandelbrot no necesita parametros de cordenadas", 48);
			t_close(f);
		}
	}
	else if (type_cmp(argv[1], "Julia"))
	{
		f->name = JULIA;
		if (!argv[2] || !argv[3] || argc > 4 || !num(argv[2]) || !num(argv[3]))
			msg_error(f);
		f->jc_re = ft_atoi(argv[2]);
		f->jc_im = ft_atoi(argv[3]);
		if (f->jc_re > 2 || f->jc_re < -2 || f->jc_im > 2 || f->jc_im < -2)
			msg_error(f);
	}
	else
		msg_error(f);
}

void	data_fractal(t_data *fractal)
{
	fractal->min_real = -2.0;
	fractal->max_real = 2.0;
	fractal->max_imagi = -2.0;
	fractal->zoom = 200;
	fractal->min_imagi = fractal->max_imagi + (fractal->max_real
			- fractal->min_real) * HEIGHT / WIDTH;
}

void	init_fractal(t_data *fractal, char **argv, int argc)
{
	set_fractal(fractal, argv, argc);
	data_fractal(fractal);
}
