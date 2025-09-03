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

void		ft_atof(int argc, char **argv, float *parameters)
{
	char	**arg_ptr;
	float	result;
	int		sign;

	sign = 1;
	result = 0;
	arg_ptr = argv + 2;
	while (argc-- > 0)
	{
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
		*parameters = result;
		parameters++;
		arg_ptr++;
	}
}

void	get_decimal(char *string, float *result, int i, int divisor)
{
	if (i < 5)
	{
		*result += (string[i] - '0') / (float) divisor;
		get_decimal(string, result, i + 1, divisor * 10);
	}
}

//	Stack overflow:
//	x_val = (x_n / W_MAX) * (1 - (-2)) + (-2), where 1 is C_max and -2 is C_min
//
//	px_val = (px_n / W_MAX) * (C_MAX - C_MIN) + C_MIN)
//	WITH ZOOM:
//	W_MAX doesn't change.
//	C_MAX and C_MIN depend on what part you zoom in and how much
//
void	zoom_in(t_fract *restrict fract, int x, int y)
{
	fract->c_max = fract->c_max / ZOOM;
	fract->c_min = fract->c_min / ZOOM;
	fract->magn = fract->c_max - fract->c_min;
	(void) x;
	(void) y;
}

void	zoom_out(t_fract *restrict fract, int x, int y)
{
	if (fract->magn < 4)
	{
		fract->c_max = fract->c_max * ZOOM;
		fract->c_min = fract->c_min * ZOOM;
		fract->magn = fract->c_max - fract->c_min;
		(void) x;
		(void) y;
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
			mlx_destroy_display(fr->mlx_ptr);
			free(fr->mlx_ptr);
		}
		free(fr);
	}
	exit(SUCCESS);
}
