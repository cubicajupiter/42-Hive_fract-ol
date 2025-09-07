/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:12:31 by jvalkama          #+#    #+#             */
/*   Updated: 2025/09/07 17:37:58 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fract		*fract;

	if (argc < 2 || argc > 4)
	{
		ft_putendl_fd("Run with argument:	./fractol <name> <julia param>", 1);
		ft_putendl_fd("Choose fract:	'mandel' / 'julia'\n", 1);
		ft_putendl_fd("Julia takes 2 args: <[-][0, 1, 2][.][decis]>", 1);
		ft_putendl_fd("(Bad parameters default to a Julia set at 0, 0)", 1);
		return (ERROR);
	}
	if (initialize(&fract, argc, argv))
	{
		clean_program(fract);
		return (ERROR);
	}
	mlx_mouse_hide(fract->mlx_ptr, fract->win_ptr);
	mlx_loop_hook(fract->mlx_ptr, &reso_iterator, fract);
	mlx_hook(fract->win_ptr, REDCROSS, 0, &closebutton, fract);
	mlx_hook(fract->win_ptr, KeyPress, KeyPressMask, &keys, fract);
	mlx_hook(fract->win_ptr, ButtonPress, ButtonPressMask, &m_btns, fract);
	mlx_loop(fract->mlx_ptr);
	clean_program(fract);
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
