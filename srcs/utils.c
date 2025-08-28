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

void	zoom_in(t_fract *fract, int x, int y)
{
	fract->magnitude = fract->magnitude / ZOOM;
	fract->c_offset = fract->magnitude / 2.; //AND MOUSE POSITION?
}

void	zoom_out(t_fract *fract, int x, int y)
{
	if (fract->magnitude < 4)
	{
		fract->magnitude = fract->magnitude * ZOOM;
		fract->c_offset = fract->magnitude / 2.; //AND MOUSE POSITION?
	}
}
