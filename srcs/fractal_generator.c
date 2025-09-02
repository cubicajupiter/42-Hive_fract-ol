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
#include <stdio.h>

static void	gen_m(t_fract *restrict fr, int re, int i, double *restrict tmp_zR);
static void	gen_j(t_fract *restrict fr, int re, int i, double *restrict tmp_zR);
static void	gen_s(t_fract *restrict fr, int re, int i, double *restrict tmp_zR);

int		gen_fr(t_fract *restrict f, int re, double *restrict tmp_zR, int i)
{
	if (f->type == MANDEL)
		gen_m(f, re, i, tmp_zR);
	else if (f->type == JULIA)
		gen_j(f, re, i, tmp_zR);
	else if (f->type == SHIP)
		gen_s(f, re, i, tmp_zR);
	return (SUCCESS);
}

static void	gen_m(t_fract *restrict fr, int re, int i, double *restrict tmp_zR)
{
	fr->y = 0;
	while (fr->y < W_HEIGHT)
	{
		fr->x = 0;
		fr->ci = (long double) (W_HEIGHT - fr->y) / W_HEIGHT * (fr->c_max - fr->c_min) + fr->c_min;  //-1 * (fr->y * fr->y_scale) + fr->offset;
		while (fr->x < W_WIDTH)
		{
			fr->zR = 0.0;
			fr->zi = 0.0;
			fr->cR = (long double) fr->x / W_WIDTH * (fr->c_max - fr->c_min) + fr->c_min; // OLD: fr->x * fr->x_scale - fr->offset;
			while (i < re)
			{
				*tmp_zR = fr->zR; //CAST TMP_ZR TO LONG DOUBLE FOR MAX PRECISION!!!
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
		fr->zi = (long double) (W_HEIGHT - fr->y) / W_HEIGHT * (fr->c_max - fr->c_min) + fr->c_min;  //-1 * (fr->y * fr->y_scale) + fr->offset;
		while (fr->x < W_WIDTH)
		{
			fr->zR = (long double) fr->x / W_WIDTH * (fr->c_max - fr->c_min) + fr->c_min;  //fr->x * fr->x_scale - fr->offset;
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

static void	gen_s(t_fract *restrict fr, int re, int i, double *restrict tmp_zR)
{
	fr->y = 0;
	while (fr->y < W_HEIGHT)
	{
		fr->x = 0;
		fr->ci = (long double) (W_HEIGHT - fr->y) / W_HEIGHT * (fr->c_max - fr->c_min) + fr->c_min;//-1 * (fr->y * fr->y_scale) + fr->offset;
		while (fr->x < W_WIDTH)
		{
			fr->zR = 0.0;
			fr->zi = 0.0;
			fr->cR = (long double) fr->x / W_WIDTH * (fr->c_max - fr->c_min) + fr->c_min;//fr->x * fr->x_scale - fr->offset;
			while (i < re)
			{
				*tmp_zR = fr->zR;
				fr->zR = (fr->zR * fr->zR) - (fr->zi * fr->zi) - fr->cR;
				fr->zi = (*tmp_zR * fr->zi);
				fr->zi = fr->zi * (fr->zi > 0) - (fr->zi < 0);
				fr->zi = 2 * fr->zi + fr->ci;
				if ((fr->zR * fr->zR + (fr->zi * fr->zi) > MAX_MAGNITUDE))
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
