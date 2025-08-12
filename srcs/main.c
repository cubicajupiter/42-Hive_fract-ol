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
		ft_printf("Run with command:		./fractol <FRACTAL NAME>\n"); //replace these with a libft function and import one less lib
		ft_printf("Available fractals:		mandelbrot, julia & burningship");
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
	fract->window = mlx_new_window(fract->mlx, 1920, 1080, "Fract-ol");
}

void	init_fract(t_fract *fract)
{
	fract->fract_img = mlx_new_image(fract->mlx, 1920, 1080);
	fract->pixel_ptr = mlx_get_data_addr(fract->fract_img, &fract->bpp, &fract->l_len, &fract->endian);
}
