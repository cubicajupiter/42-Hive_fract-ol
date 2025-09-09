/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:13:02 by jvalkama          #+#    #+#             */
/*   Updated: 2025/09/09 12:23:08 by jvalkama         ###   ########.fr       */
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

int	pre_check_args(char **av)
{
	int		n_arg;
	char	*arg;

	n_arg = 2;
	while (n_arg < 4)
	{
		arg = av[n_arg];
		if (arg[0] == '-')
		{
			if (check_argument(arg + 1))
				return (ERROR);
		}
		else if (arg[0] >= '0' && arg[0] <= '2')
		{
			if (check_argument(arg))
				return (ERROR);
		}
		else
			return (ERROR);
		n_arg++;
	}
	return (SUCCESS);
}

int	check_argument(char *arg)
{
	int		i;

	if (arg[0] < '0' || arg[0] > '2')
		return (ERROR);
	if (arg[1] != '.')
		return (ERROR);
	i = 2;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (ERROR);
		i++;
	}
	if (i == 2)
		return (ERROR);
	return (SUCCESS);
}
