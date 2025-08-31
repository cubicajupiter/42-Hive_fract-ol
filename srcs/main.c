/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:12:31 by jvalkama          #+#    #+#             */
/*   Updated: 2025/08/11 14:13:23 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char *argv[])
{
	t_fract		*fract;

	if (argc < 2 || argc > 4)
	{
		ft_putendl_fd("Run with argument:	./fractol <FRACTAL NAME> <julia param>", 1);
		ft_putendl_fd("Fractal name arguments:	'mandel', 'julia', 'ship'\n", 1);
		ft_putendl_fd("Julia takes two arguments:	<[-][0, 1, 2][.][decimals]>", 1);
		ft_putendl_fd("(Bad parameters default to a Julia set at 0, 0)", 1);
		return (ERROR);
	}
	if (initialize(&fract, argc, argv))
	{
		free(fract); //should actually free all the mlx bullshit also i think
		return (ERROR);
	}
	mlx_loop_hook(fract->mlx_ptr, &reso_iterator, fract);
	mlx_hook(fract->win_ptr, REDCROSS, 0, &closebutton, fract);
	mlx_hook(fract->win_ptr, KeyPress, KeyPressMask, &keys, fract);
	mlx_hook(fract->win_ptr, ButtonPress, ButtonPressMask, &mousebuttons, fract);
	mlx_loop(fract->mlx_ptr);
	mlx_destroy_display(fract->mlx_ptr);
	free(fract->mlx_ptr);
	return (SUCCESS);
}

int	initialize(t_fract **fract, int argc, char **argv)
{
	*fract = malloc(sizeof(t_fract));
	if (!*fract)
		return (ERROR);
	if (init_mlx(*fract))
		return (ERROR);
	if (init_fract(*fract, argc, argv))
		return (ERROR);
	init_colors(*fract);
	init_planar_values(*fract);
	return (SUCCESS);
}
