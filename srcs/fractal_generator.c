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

#include "../includes/fractol.h"

int		gen_fract_type(int argc, char *argv[], t_fract *fract)
{
	double		*save_zR;

	*save_zR = 0.0;
	init_members(fract);
	if (ft_strncmp(argv[1], "mandel", 7))
		gen_mandel(fract, 0, save_zR);
	else if (ft_strncmp(argv[1], "julia", 6))
	{
		init_julia(fract, argc - 2, argv);
		gen_julia(fract, 0, save_zR);
	}
	else if (ft_strncmp(argv[1], "ship", 5))
		gen_ship(fract, 0, save_zR);
	else
	{
		ft_putendl_fd("Choose type: mandel, julia, ship", 1);
		return (ERROR);
	}
	return (0);
}


void	gen_mandel(t_fract *fr, int i, double *save_zR)
{
	while (fr->y < W_HEIGHT)
	{
		fr->x = 0;
		while (fr->x < W_WIDTH)
		{
			fr->zR = 0.0;
			fr->zi = 0.0;
			fr->cR = fr->x * fr->x_scale - 2.;
			fr->ci = fr->y * fr->y_scale + 2.;
			while (i < MAX_ITERS)
			{
				*save_zR = fr->zR;
				fr->zR = (fr->zR * fr->zR) + (-1 * fr->zi * fr->zi);
				fr->zi = (*save_zR * fr->zi) * 2;
				fr->zR += fr->cR;
				fr->zi += fr->ci;
				if ((fr->zR * fr->zR) + (fr->zi * fr->zi) > 4)
					break ;
				i++;
			}
			blit_px_to_img(fr, i);
			i = 0;
			fr->x++;
		}
	}
}

void	gen_julia(t_fract *fr, int i, double *save_zR)
{
	while (fr->y < W_HEIGHT)
	{
		fr->x = 0;
		while (fr->x < W_WIDTH)
		{
			fr->zR = fr->x * fr->x_scale - 2.;
			fr->zi = fr->y * fr->y_scale + 2.;
			while (i < MAX_ITERS)
			{
				*save_zR = fr->zR;
				fr->zR = (fr->zR * fr->zR) + (-1 * fr->zi * fr->zi);
				fr->zi = (*save_zR * fr->zi) * 2;
				fr->zR += fr->cR;
				fr->zi += fr->ci;
				if ((fr->zR * fr->zR) + (fr->zi * fr->zi) > 4)
					break ;
				i++;
			}
			blit_px_to_img(fr, i);
			i = 0;
			fr->x++;
		}
	}
}

void	gen_ship(t_fract *fr, int i, double *save_zR)
{
	while (fr->y < W_HEIGHT)
	{
		fr->x = 0;
		while (fr->x < W_WIDTH)
		{
			fr->zR = 0.0;
			fr->zi = 0.0;
			fr->cR = fr->x * fr->x_scale - 2.;
			fr->ci = fr->y * fr->y_scale + 2.;
			while (i < MAX_ITERS)
			{
				*save_zR = fr->zR;
				fr->zR = (fr->zR * fr->zR) - (fr->zi * fr->zi) - fr->cR;
				fr->zi = (*save_zR * fr->zi);
				fr->zi = fr->zi * (fr->zi > 0) - (fr->zi < 0);
				fr->zi = 2 * fr->zi + fr->ci;
				if ((fr->zR * fr->zR + (fr->zi * fr->zi) > 4))
					break ;
				i++;
			}
			blit_px_to_img(fr, i);
			i = 0;
			fr->x++;
		}
	}
}
