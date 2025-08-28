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
	t_fract		fract;

	if (argc < 2 || argc > 3)
	{
		ft_putendl_fd("Run with argument:		./fractol <FRACTAL NAME> <extra argument>", 1);
		ft_putendl_fd("Fractal name arguments:		'mandel', 'julia', 'ship'\n", 1);
		ft_putendl_fd("Julia takes up to two extra parameter arguments:	<[-][0, 1, 2][.][any number of decimals]>", 1);
		ft_putendl_fd("(Bad parameters default to a Julia set at 0, 0)", 1);
		return (ERROR);
	}
	initialize(&fract);
	if (gen_fract_type(argc, argv, &fract))
		return (ERROR);
	render(&fract);

	mlx_loop_hook(fract.mlx_ptr, &handle_no_event, &fract); //insert gen_fract in loop_hook
	mlx_hook(fract.win_ptr, 17, 0, &close_window, &fract);
	mlx_hook(fract.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &fract);
	mlx_hook(fract.win_ptr, ButtonPress, ButtonPressMask, &handle_mousescroll, &fract);

	mlx_loop(fract.mlx_ptr);
	mlx_destroy_display(fract.mlx_ptr);
	free(fract.mlx_ptr);
	return (0);
}

void	initialize(t_fract *fract)
{
	init_mlx(fract);
	init_fract(fract);
	init_colors(fract);
	init_planar_values(fract);
}
