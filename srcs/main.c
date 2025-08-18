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

	if (argc < 2 || argc > 3)
	{
		ft_putendl("Run with argument:		./fractol <FRACTAL NAME> <extra argument>\n");
		ft_putendl("Fractal name arguments:		'mandel', 'julia', 'ship'");
		ft_putendl("Extra parameter argument for julia (a decimal value):	<[-][0, 1, 2].[max 5 decimals]>");
		ft_putendl("(Wrongful extra argument defaults to a Julia at 0, 0)");
		return (ERROR);
	}
	initialize_tools(&fract); // does this initialize everything with every cycle of the mlx loop????????
	if (assign_fract_type(argv, &fract));
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
	color = 0x0D0D3B; //darker shade of midnight blue, nearly black. First shade (background).
	gradient_offset = 0; //need a way to iterate through hexes for a gradient
	while (i < MAX_ITERS)
	{
		fract->colors[i] = color + gradient_offset;
		gradient_offset += ; //could even iterate the gradient offset for added effect...
		i++;
	}
}
