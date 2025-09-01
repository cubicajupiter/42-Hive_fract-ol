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

void	zoom_in(t_fract *restrict fract, int x, int y)
{
	fract->magnitude = fract->magnitude / ZOOM;
	fract->offset = fract->magnitude / 2; //AND MOUSE POSITION?
	fract->x_scale = fract->magnitude / W_WIDTH;
	fract->y_scale = fract->magnitude / W_HEIGHT * -1;
	fract->y_zoom = fract->y_scale + fract->offset;
	fract->x_zoom = fract->x_scale - fract->offset;
	(void) x;
	(void) y;
}

void	zoom_out(t_fract *restrict fract, int x, int y)
{
	if (fract->magnitude < 4)
	{
		fract->magnitude = fract->magnitude * ZOOM;
		fract->offset = fract->magnitude / 2; //AND MOUSE POSITION?
		fract->x_scale = fract->magnitude / W_WIDTH;
		fract->y_scale = fract->magnitude / W_HEIGHT * -1;
		fract->y_zoom = fract->y_scale + fract->offset;
		fract->x_zoom = fract->x_scale - fract->offset;
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
