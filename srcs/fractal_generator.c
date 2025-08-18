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

#include <math.h>
#include "../includes/fractol.h"

void	generate_fractal(int type, t_fract *fr)
{
	fr->x = 0;
	fr->y = 0;
	fr->x_scale = 4 / W_WIDTH;
	fr->y_scale = 4 / W_HEIGHT * -1;
	while (fr->y < W_HEIGHT)
	{
		while (fr->x < W_WIDTH)
		{
			if (type == MANDEL)
				gen_mandel_px(fr);
			else if (type == JULIA)
				gen_julia_px(fr);
			else if (type == SHIP)
				gen_ship_px(fr);
			blit_px_to_img(fr);
			fr->x++;
		}
		fr->x = 0;
		fr->y++;
	}
}

void	gen_mandel_px(t_fract *fr)
{
	int			i;
	double		temp_zR;
	
	i = 0;
	fr->zR = 0.0;
	fr->zi = 0.0;
	fr->ci = fr->y * fr->y_scale + 2.;
	fr->cR = fr->x * fr->x_scale - 2.;
	while (i < MAX_ITERS)
	{
		temp_zR = fr->zR;
		fr->zR = (fr->zR * fr->zR) + (-1 * fr->zi * fr->zi);
		fr->zi = (temp_zR * fr->zi) * 2;
		fr->zR += fr->cR;
		fr->zi += fr->ci;
		if ((fr->zR * fr->zR) + (fr->zi * fr->zi) > 4)
		{
			fr->i = i;
			break;
		}
		i++;
	}
}

void	gen_julia_px(t_fract *fr)
{
	fr->zR = ;
	fr->zi = ;
	fr->cR = ;
	fr->ci = ;
	float *famous = [0.763, 0.086];
}

void	gen_ship_px(t_fract *fr)
{
	
}
