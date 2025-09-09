/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:12:31 by jvalkama          #+#    #+#             */
/*   Updated: 2025/09/07 17:52:20 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char *av[])
{
	t_fract		*fract;

	if (ac < 2 || ac > 4)
	{
		ft_putendl_fd("Usage: ./fractol <NAME> <2 PARAMS IF JULIA>", 1);
		ft_putendl_fd("NAME:  'mandel' 'julia'\n", 1);
		ft_putendl_fd("JULIA PARAM: <[-][0, 1, 2].[0 - 9]>", 1);
		return (ERROR);
	}
	if (initialize(&fract, ac, av))
		clean_program(fract);
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

void	clean_program(t_fract *fract)
{
	ft_putendl_fd("[ USAGE ]\nNAME: 'mandel' / 'julia'", 1);
	ft_putendl_fd("JULIA PARAMS: <[-][0, 1, 2].[0 - 9]>", 1);
	ft_putendl_fd("Mandel takes no parameters!\nJulia takes two FLOATS!", 1);
	if (fract)
	{
		if (fract->img && fract->mlx_ptr)
			mlx_destroy_image(fract->mlx_ptr, fract->img);
		if (fract->win_ptr && fract->mlx_ptr)
			mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
		if (fract->mlx_ptr)
		{
			mlx_loop_end(fract->mlx_ptr);
			mlx_destroy_display(fract->mlx_ptr);
			free(fract->mlx_ptr);
		}
		free(fract);
	}
	exit(SUCCESS);
}
