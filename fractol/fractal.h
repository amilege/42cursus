/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:06:07 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/06 10:38:07 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <unistd.h>
# define HEIGHT 600
# define WIDTH 800
# define JULIA 0
# define MANDELBROT 1
# define MAX_ITER 200
# define EVENT_CLOSE_WIN 17
# define K_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_MINUS 27
# define KEY_PLUS 24
# define MOUSE_SCROLL_UP 5
# define MOUSE_SCROLL_DOWN 4

typedef struct s_data
{
	void	*mlx;
	int		name;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		color;
	int		bits_per_pixel;
	int		line_length;
	double	min_real;
	double	max_real;
	double	min_imagi;
	double	max_imagi;
	double	zoom;
	double	x;
	double	y;
	double	jc_re;
	double	jc_im;
	int		it_num;

}			t_data;

int			key_hook(int keycode, t_data *vars);
int			mouse_event(int key, int x, int y, t_data *f);
void		zoom(t_data *f, double zoom);
void		move(t_data *f, double direct, char type);
void		clean_all(t_data *fractal);
void		init_fractal(t_data *fractal, char **argv, int argc);
int			render(t_data *fractal);
int			mandelbrot(double y0, double x0);
int			julia(t_data *fractaL, double z_re, double z_im);
void		set_pixel_color(t_data *fractal, int color);
int			end_fractol(void);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			set_color(int iter);
void		init_win(t_data *fractal);
void		reinit(t_data *fractal);
void		*ft_calloc(int count, int size);
int			t_close(t_data *f);
void		applyZoom(t_data *f, double mouseRe, double mouseIm,
				double zoomFactor);
int			hook_mousedown(t_data *f);
void		init_hook(t_data *fractal, char **argv, int argc);
double		ft_atoi(char *str);
double		decimals(double x, char *str, int i, int sign);
int			num(char *str);
int			isdigit(int c);
int			msg_error(t_data *fractal);

#endif
