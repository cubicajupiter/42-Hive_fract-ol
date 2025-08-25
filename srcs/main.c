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
	if (gen_fract_type(argc, argv, &fract))
		return (ERROR);
	render(&fract);

	mlx_loop_hook(fract.mlx_ptr, &handle_no_event, &fract);
	mlx_hook(fract.win_ptr, 17, 0, &close_window, &fract);
	mlx_hook(fract.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &fract);
	mlx_hook(fract.win_ptr, ButtonPress, ButtonPressMask, &handle_mousescroll, &fract);

	mlx_loop(fract.mlx_ptr);
	mlx_destroy_display(fract.mlx_ptr);
	free(fract.mlx_ptr);
	return (0);
}

void	initialize_tools(t_fract *fract)
{
	init_mlx(fract);
	init_fract(fract);
	init_colors(fract);
}

int		init_mlx(t_fract *fract)
{
	fract->mlx_ptr = mlx_init(); //returns a void pointer. BUilds a "generic" - with address, without type.
	if (!fract->mlx_ptr)
		return (MLX_ERROR);
	fract->win_ptr = mlx_new_window(fract->mlx_ptr), W_WIDTH, W_HEIGHT, "Fract-ol");
	if (!fract->win_ptr)
		return (MLX_ERROR);
	return (0);
}

void	init_fract(t_fract *fra)
{
	fra->img = mlx_new_image(fra->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!fra->img)
		return (ERROR);
	fra->px_ptr = mlx_get_data_addr(fra->img, &fra->bpp, &fra->l_len, &fra->e);
	if (!fra->px_ptr)
		return (ERROR);
	return (0);

void	init_colors(t_fract *fract)
{
	int		i;
	int		color;
	int		gradient_offset;

	i = 0;
	color = 0xTTRRGGBB;
	gradient_offset = 0;
	while (i < MAX_ITERS)
	{
		fract->colors[i] = color + gradient_offset;
		gradient_offset += 0; //needs a good offset for gradient. Niklas: red loops up and down, green increase to full, blue increase to halfway.
		i++;
	}
}
