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

int		assign_fract_type(char *argv[], t_fract *fract)
{
	float	parameter_spec;

	if (ft_strncmp(argv[1], "mandel", 7))
		generate_fractal(MANDEL, &fract, NONE);
	else if (ft_strncmp(argv[1], "julia", 6))
	{
		parameter_spec = atof(argv[2]); //need two floats (two extra args) btw
		generate_fractal(JULIA, &fract, parameter_spec);
	}
	else if (ft_strncmp(argv[1], "ship", 5))
		generate_fractal(SHIP, &fract, NONE);
	else
	{
		ft_putendl(1, "Choose type: mandel, julia, ship\n", 33);
		return (ERROR);
	}
	return (0);
}

float	atof(char *arg)
{
	float	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	if (arg[i] == '-')
	{
		sign *= -1;
		i++;
	}	
	if (arg[i] >= '0' && arg[i] <= '2')
	{
		result += arg[i] - '0';
		i++;
	}
	if (arg[i] != '.')
		return (0)
	while (arg[i])
	{
		result += 0.1 * arg[i] - '0';
	}
	return (0);
}
