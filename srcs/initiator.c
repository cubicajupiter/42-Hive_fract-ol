/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:37:54 by jvalkama          #+#    #+#             */
/*   Updated: 2025/09/09 12:18:40 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_mlx(t_fract *f)
{
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		return (ERROR);
	f->win_ptr = mlx_new_window(f->mlx_ptr, W_WIDTH, W_HEIGHT, "Fract-ol");
	if (!f->win_ptr)
		return (ERROR);
	return (SUCCESS);
}

int	init_fract(t_fract *f, int ac, char **av)
{
	f->img = mlx_new_image(f->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!f->img)
		return (ERROR);
	f->px_ptr = mlx_get_data_addr(f->img, &f->bpp, &f->l_len, &f->e);
	f->px_int_ptr = (int *) f->px_ptr;
	if (!f->px_ptr)
		return (ERROR);
	if (!ft_strncmp(av[1], "mandel", 7) && ac == 2)
		f->type = MANDEL;
	else if (!ft_strncmp(av[1], "julia", 6) && ac == 4)
	{
		init_julia(f, ac - 2, av);
		f->type = JULIA;
	}
	else
		return (ERROR);
	return (SUCCESS);
}

void	init_planar_values(t_fract *f)
{
	f->x_max = 2.;
	f->x_min = -2.5;
	f->y_max = 2.;
	f->y_min = -2.5;
	f->magn = f->x_max - f->x_min;
	f->zoom_lvl = 1;
	f->int_step = f->l_len / 4;
}

void	init_colors(t_fract *f)
{
	int		i;
	int		color;
	int		gradient_offset;

	i = 0;
	color = 0x50e96769;
	gradient_offset = 1;
	while (i < MAX_ITERS)
	{
		f->colors[i] = color + gradient_offset;
		gradient_offset += 567;
		i++;
	}
}

void	init_julia(t_fract *f, int ac, char **av)
{
	float	params[2];

	if (pre_check_args(av))
	{
		ft_putendl_fd("Bad Julia parameters.", 1);
		clean_program(f);
	}
	ft_atof(ac, av, params);
	f->zr = 0.0;
	f->zi = 0.0;
	f->cr = (long double) params[0];
	f->ci = (long double) params[1];
}
