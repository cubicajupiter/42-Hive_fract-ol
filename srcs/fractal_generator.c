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

static void	gen_m(t_fract *restrict fr, int re, int i, double *restrict tmp_zR);
static void	gen_j(t_fract *restrict fr, int re, int i, double *restrict tmp_zR);

int		gen_fr(t_fract *restrict f, double *restrict tmp_zR, int i)
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
		gen_m(f, reso, i, tmp_zR);
	else if (f->type == JULIA)
		gen_j(f, reso, i, tmp_zR);
	f->colors[reso] = prev_col;
	return (SUCCESS);
}

static void	gen_m(t_fract *restrict fr, int re, int i, double *restrict tmp_zR)
{
	fr->y = 0;
	while (fr->y < W_HEIGHT)
	{
		fr->x = 0;
		fr->ci = (long double) (W_HEIGHT - fr->y) / W_HEIGHT * fr->magn + fr->y_min;
		while (fr->x < W_WIDTH)
		{
			fr->zR = 0.0;
			fr->zi = 0.0;
			fr->cR = (long double) fr->x / W_WIDTH * fr->magn + fr->x_min;
			while (i < re)
			{
				*tmp_zR = fr->zR;
				fr->zR = (fr->zR * fr->zR) - (fr->zi * fr->zi) + fr->cR;
				fr->zi = 2 * (*tmp_zR * fr->zi) + fr->ci;
				if ((fr->zR * fr->zR) + (fr->zi * fr->zi) > MAX_MAGNITUDE)
					break ;
				i++;
			}
			fr->px_int_ptr[(fr->y * fr->l_len / 4) + fr->x] = fr->colors[i];
			i = 0;
			fr->x++;
		}
		fr->y++;
	}
}

static void	gen_j(t_fract *restrict fr, int re, int i, double *restrict tmp_zR)
{
	fr->y = 0;
	while (fr->y < W_HEIGHT)
	{
		fr->x = 0;
		while (fr->x < W_WIDTH)
		{
			fr->zi = (long double) (W_HEIGHT - fr->y) / W_HEIGHT * fr->magn + fr->y_min;
			fr->zR = (long double) fr->x / W_WIDTH * fr->magn + fr->x_min;
			while (i < re)
			{
				*tmp_zR = fr->zR;
				fr->zR = (fr->zR * fr->zR) - (fr->zi * fr->zi) + fr->cR;
				fr->zi = 2 * (*tmp_zR * fr->zi) + fr->ci;
				if ((fr->zR * fr->zR) + (fr->zi * fr->zi) > MAX_MAGNITUDE)
					break ;
				i++;
			}
			fr->px_int_ptr[(fr->y * fr->l_len / 4) + fr->x] = fr->colors[i];
			i = 0;
			fr->x++;
		}
		fr->y++;
	}
}
