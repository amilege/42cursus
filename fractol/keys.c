/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:56:16 by amile-ge          #+#    #+#             */
/*   Updated: 2024/04/11 11:33:56 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"

int	mouse_event(int mouse, int x, int y, t_data *f)
{
	x = y;
	if (mouse == MOUSE_SCROLL_UP)
		zoom(f, 1.1);
	else if (mouse == MOUSE_SCROLL_DOWN)
		zoom(f, 0.8);
	render(f);
	return (0);
}

void	move(t_data *f, double direct, char type)
{
	double	center_re;
	double	center_im;

	center_re = f->max_real - f->min_real;
	center_im = f->max_imagi - f->min_imagi;
	if (type == 'D')
	{
		f->max_imagi += center_im * direct;
		f->min_imagi += center_im * direct;
	}
	else if (type == 'U')
	{
		f->max_imagi += center_im * direct;
		f->min_imagi += center_im * direct;
	}
	else if (type == 'R')
	{
		f->max_real += center_re * direct;
		f->min_real += center_re * direct;
	}
	else if (type == 'L')
	{
		f->max_real += center_re * direct;
		f->min_real += center_re * direct;
	}
}

void	zoom(t_data *f, double zoom)
{
	double	center_re;
	double	center_im;
	double	range_re;
	double	range_im;

	center_re = (f->min_real + f->max_real) / 2.0;
	center_im = (f->min_imagi + f->max_imagi) / 2.0;
	range_re = (f->max_real - f->min_real) / 2.0;
	range_im = (f->max_imagi - f->min_imagi) / 2.0;
	f->min_real = center_re - range_re * zoom;
	f->max_real = center_re + range_re * zoom;
	f->min_imagi = center_im - range_im * zoom;
	f->max_imagi = center_im + range_im * zoom;
}

int	key_hook(int keycode, t_data *f)
{
	if (keycode == K_ESC)
	{
		t_close(f);
		return (0);
	}
	else if (keycode == KEY_MINUS)
		zoom(f, 2.0);
	else if (keycode == KEY_PLUS)
		zoom(f, 0.5);
	else if (keycode == KEY_UP)
		move(f, 0.2, 'U');
	else if (keycode == KEY_DOWN)
		move(f, -0.2, 'D');
	else if (keycode == KEY_RIGHT)
		move(f, 0.2, 'R');
	else if (keycode == KEY_LEFT)
		move(f, -0.2, 'L');
	else
		return (1);
	render(f);
	return (0);
}
