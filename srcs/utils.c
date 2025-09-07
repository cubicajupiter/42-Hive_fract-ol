/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:35:35 by jvalkama          #+#    #+#             */
/*   Updated: 2025/08/18 16:53:57 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_atof(int argc, char **argv, float *parameters)
{
	char		**arg_ptr;
	float		result;
	int			sign;

	arg_ptr = argv + 2;
	while (argc-- > 0)
	{
		sign = 1;
		result = 0.0;
		if (**arg_ptr == '-')
		{
			sign *= -1;
			(*arg_ptr)++;
		}
		if (**arg_ptr >= '0' && **arg_ptr <= '2')
		{
			result += **arg_ptr - '0';
			(*arg_ptr)++;
		}
		if (**arg_ptr == '.')
			get_decimal(*arg_ptr + 1, &result, 0, 10);
		*parameters = result * sign;
		parameters++;
		arg_ptr++;
	}
}

void	get_decimal(char *string, float *result, int i, int divisor)
{
	if (string[i] && i < 5)
	{
		*result += (string[i] - '0') / (float) divisor;
		get_decimal(string, result, i + 1, divisor * 10);
	}
}

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
	}
}

void	clean_program(t_fract *fr)
{
	if (fr)
	{
		if (fr->img && fr->mlx_ptr)
			mlx_destroy_image(fr->mlx_ptr, fr->img);
		if (fr->win_ptr && fr->mlx_ptr)
			mlx_destroy_window(fr->mlx_ptr, fr->win_ptr);
		if (fr->mlx_ptr)
		{
			mlx_loop_end(fr->mlx_ptr);
			mlx_destroy_display(fr->mlx_ptr);
			free(fr->mlx_ptr);
		}
		free(fr);
	}
	exit(SUCCESS);
}
