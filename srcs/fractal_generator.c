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

int		gen_fr(t_fract *restrict f, int re, double *restrict tmp_zR, int i)
{
	if (f->type == MANDEL)
		gen_m(f, res, i, tmp_zR);
	else if (f->type == JULIA)
		gen_j(f, res, i, tmp_zR);
	else if (f->type == SHIP)
		gen_s(f, res, i, tmp_zR);
	mlx_put_image_to_window(f->mlx, f->window, f->fract_img, 0, 0);
	return (SUCCESS);
}


static void	gen_m(t_fract *restrict fr, int re, int i, double *restrict tmp_zR)
{
	while (fr->y < W_HEIGHT)
	{
		fr->x = 0;
		fr->ci = fr->y * fr->y_zoom;
		while (fr->x < W_WIDTH)
		{
			fr->zR = 0.0;
			fr->zi = 0.0;
			fr->cR = fr->x * fr->x_zoom;
			while (i < res)
			{
				*tmp_zR = fr->zR;
				fr->zR = (fr->zR * fr->zR) - (fr->zi * fr->zi);
				fr->zi = 2 * (*tmp_zR * fr->zi) + fr->ci;
				fr->zR += fr->cR;
				if ((fr->zR * fr->zR) + (fr->zi * fr->zi) > MAX_MAGNITUDE)
					break ;
				i++;
			}
			fr->pixel_ptr[fr->y * fr->l_len + fr->x * fr->bpp_to_px] = fr->colors[i];
			i = 0;
			fr->x++;
		}
		fr->y++;
	}
}

static void	gen_j(t_fract *restrict fr, int re, int i, double *restrict tmp_zR)
{
	while (fr->y < W_HEIGHT)
	{
		fr->x = 0;
		fr->zi = fr->y * fr->y_zoom;
		while (fr->x < W_WIDTH)
		{
			fr->zR = fr->x * fr->x_zoom;
			while (i < res)
			{
				*tmp_zR = fr->zR;
				fr->zR = (fr->zR * fr->zR) - (fr->zi * fr->zi);
				fr->zi = 2 * (*tmp_zR * fr->zi) + fr->ci;
				fr->zR += fr->cR;
				if ((fr->zR * fr->zR) + (fr->zi * fr->zi) > MAX_MAGNITUDE)
					break ;
				i++;
			}
			fr->pixel_ptr[fr->y * fr->l_len + fr->x * fr->bpp_to_px] = fr->colors[i];
			i = 0;
			fr->x++;
		}
		fr->y++;
	}
}

static void	gen_s(t_fract *restrict fr, int re, int i, double *restrict tmp_zR)
{
	while (fr->y < W_HEIGHT)
	{
		fr->x = 0;
		fr->ci = fr->y * fr->y_zoom;
		while (fr->x < W_WIDTH)
		{
			fr->zR = 0.0;
			fr->zi = 0.0;
			fr->cR = fr->x * fr->x_zoom;
			while (i < res)
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
			fr->pixel_ptr[fr->y * fr->l_len + fr->x * fr->bpp_to_px] = fr->colors[i];
			i = 0;
			fr->x++;
		}
		fr->y++;
	}
}
