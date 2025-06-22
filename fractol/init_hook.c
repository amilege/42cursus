/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:29:16 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/06 10:17:23 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void	init_hook(t_data *fractal, char **argv, int argc)
{
	init_fractal(fractal, argv, argc);
	render(fractal);
	mlx_hook(fractal->mlx_win, 2, 0, key_hook, fractal);
	mlx_mouse_hook(fractal->mlx_win, mouse_event, fractal);
	mlx_hook(fractal->mlx_win, 17, 0L, t_close, fractal);
	mlx_loop(fractal->mlx);
}
