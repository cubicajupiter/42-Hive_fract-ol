/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoomer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:14:00 by jvalkama          #+#    #+#             */
/*   Updated: 2025/09/09 12:18:32 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fract *restrict fr, int x, int y)
{
	long double		mouse_i;
	long double		mouse_r;

	mouse_i = (long double)(W_HEIGHT - y) / W_HEIGHT * fr->magn + fr->y_min;
	mouse_r = (long double) x / W_WIDTH * fr->magn + fr->x_min;
	fr->magn = fr->magn / ZOOM;
	fr->y_max = mouse_i + fr->magn / 2.0;
	fr->y_min = mouse_i - fr->magn / 2.0;
	fr->x_max = mouse_r + fr->magn / 2.0;
	fr->x_min = mouse_r - fr->magn / 2.0;
	fr->zoom_lvl++;
	mlx_mouse_move(fr->mlx_ptr, fr->win_ptr, W_WIDTH / 2, W_HEIGHT / 2);
}

void	zoom_out(t_fract *restrict fr, int x, int y)
{
	long double		mouse_i;
	long double		mouse_r;

	if (fr->zoom_lvl > 1)
	{
		mouse_i = (long double)(W_HEIGHT - y) / W_HEIGHT * fr->magn + fr->y_min;
		mouse_r = (long double) x / W_WIDTH * fr->magn + fr->x_min;
		fr->magn = fr->magn * ZOOM;
		fr->y_max = mouse_i + fr->magn / 2.0;
		fr->y_min = mouse_i - fr->magn / 2.0;
		fr->x_max = mouse_r + fr->magn / 2.0;
		fr->x_min = mouse_r - fr->magn / 2.0;
		fr->zoom_lvl--;
		mlx_mouse_move(fr->mlx_ptr, fr->win_ptr, W_WIDTH / 2, W_HEIGHT / 2);
	}
}
