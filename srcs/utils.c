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

#include "../includes/fractol.h"

void		init_members(t_fract *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->x_scale = 4.0 / W_WIDTH;
	fract->y_scale = 4.0 / W_HEIGHT * -1;
}

void		init_julia(t_fract *fract, int argc, char **argv)
{
	float	params[2];

	params[0] = 0.0;
	params[1] = 0.0;
	ft_atof(argc, argv, params);
	fract->cR = params[0];
	fract->ci = params[1];
}

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


