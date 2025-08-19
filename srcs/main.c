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

#include "../includes/fractol.h"

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
	initialize_tools(&fract);
	if (assign_fract_type(argc, argv, &fract))
		return (ERROR);
	render(&fract);
	mlx_loop(fract.mlx);
	return (0);
}

void	initialize_tools(t_fract *fract)
{
	init_mlx(fract);
	init_fract(fract);
	init_colors(fract);
}

void	init_mlx(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->window = mlx_new_window(fract->mlx, W_WIDTH, W_HEIGHT, "Fract-ol");
}

void	init_fract(t_fract *fra)
{
	fra->img = mlx_new_image(fra->mlx, W_WIDTH, W_HEIGHT);
	fra->px_ptr = mlx_get_data_addr(fra->img, &fra->bpp, &fra->l_len, &fra->e);
}

void	init_colors(t_fract *fract)
{
	int		i;
	int		color;
	int		gradient_offset;

	i = 0;
	color = 0x0D0D3B;
	gradient_offset = 0;
	while (i < MAX_ITERS)
	{
		fract->colors[i] = color + gradient_offset;
		gradient_offset += 0; //needs a good offset for gradient. Niklas: red loops up and down, green increase to full, blue increase to halfway.
		i++;
	}
}
