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
#include "../includes/mlx_linux/mlx.h"
#include "../includes/libft/libft.h"

// METASKILLS: code completion vim default: CTRL+Y

int		main(int argc, char *argv[])
{
	t_fract		fract;

	if (argc != 2)
	{
		ft_putendl("Run with argument:		./fractol <FRACTAL NAME>");
		ft_putendl("Available arguments:		mandel, julia & ship");
		return (0);
	}
	initialize_tools(&fract);
	generate_fractal(argv[1], &fract);
	render(&fract);	
	mlx_loop(fract.mlx);

	return (0);
}

void	initialize_tools(t_fract *fract)
{
	init_mlx(fract);
	init_fract(fract);
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
