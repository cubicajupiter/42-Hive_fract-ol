/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:02:21 by jvalkama          #+#    #+#             */
/*   Updated: 2025/08/18 10:59:48 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	gen_m(t_fract *restrict fr, int re, int i, long double *tmp_zr);
static void	gen_j(t_fract *restrict fr, int re, int i, long double *tmp_zr);

int	gen_fr(t_fract *f, long double *tmp_zr, int i)
{
	static int	reso = 3;
	static int	zoom_lvl;
	int			prev_col;

	if (f->zoom_lvl != zoom_lvl)
	{
		zoom_lvl = f->zoom_lvl;
		reso = 3 + zoom_lvl;
	}
	if (reso < MAX_ITERS)
		reso++;
	prev_col = f->colors[reso];
	f->colors[reso] = 0x00000000;
	if (f->type == MANDEL)
		gen_m(f, reso, i, tmp_zr);
	else if (f->type == JULIA)
		gen_j(f, reso, i, tmp_zr);
	f->colors[reso] = prev_col;
	return (SUCCESS);
}

static void	gen_m(t_fract *restrict f, int re, int i, long double *tmp_zr)
{
	f->y = 0;
	while (f->y < W_HEIGHT)
	{
		f->x = 0;
		f->ci = (float)(W_HEIGHT - f->y) / W_HEIGHT * f->magn + f->y_min;
		while (f->x < W_WIDTH)
		{
			f->zr = 0.0;
			f->zi = 0.0;
			f->cr = (float) f->x / W_WIDTH * f->magn + f->x_min;
			while (i < re)
			{
				*tmp_zr = f->zr;
				f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->cr;
				f->zi = 2 * (*tmp_zr * f->zi) + f->ci;
				if ((f->zr * f->zr) + (f->zi * f->zi) > MAX_MAGNITUDE)
					break ;
				i++;
			}
			f->px_int_ptr[(f->y * f->int_step) + f->x] = f->colors[i];
			i = 0;
			f->x++;
		}
		f->y++;
	}
}

static void	gen_j(t_fract *restrict f, int re, int i, long double *tmp_zr)
{
	f->y = 0;
	while (f->y < W_HEIGHT)
	{
		f->x = 0;
		while (f->x < W_WIDTH)
		{
			f->zi = (float)(W_HEIGHT - f->y) / W_HEIGHT * f->magn + f->y_min;
			f->zr = (float) f->x / W_WIDTH * f->magn + f->x_min;
			while (i < re)
			{
				*tmp_zr = f->zr;
				f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->cr;
				f->zi = 2 * (*tmp_zr * f->zi) + f->ci;
				if ((f->zr * f->zr) + (f->zi * f->zi) > MAX_MAGNITUDE)
					break ;
				i++;
			}
			f->px_int_ptr[(f->y * f->int_step) + f->x] = f->colors[i];
			i = 0;
			f->x++;
		}
		f->y++;
	}
}
