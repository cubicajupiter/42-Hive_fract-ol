#include "fractol.h"

int	init_mlx(t_fract *fra)
{
	fra->mlx_ptr = mlx_init(); //returns a void pointer. BUilds a "generic" - with address, without type.
	if (!fra->mlx_ptr)
		return (MLX_ERROR);
	fra->win_ptr = mlx_new_window(fra->mlx_ptr), W_WIDTH, W_HEIGHT, "Fract-ol");
	if (!fra->win_ptr)
		return (MLX_ERROR);
	return (0);
}

int	init_fract(t_fract *fra)
{
	fra->img = mlx_new_image(fra->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!fra->img)
		return (ERROR);
	fra->px_ptr = mlx_get_data_addr(fra->img, &fra->bpp, &fra->l_len, &fra->e);
	if (!fra->px_ptr)
		return (ERROR);
	return (0);
}

void	init_planar_values(t_fract *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->magnitude = 4.0;
	fract->c_offset = fract->magnitude / 2.;
	fract->x_scale = fract->magnitude / W_WIDTH;
	fract->y_scale = fract->magnitude / W_HEIGHT * -1;
}

void	init_colors(t_fract *fra)
{
	int		i;
	int		color;
	int		gradient_offset;

	i = 0;
	color = 0xTTRRGGBB;
	gradient_offset = 0;
	while (i < MAX_ITERS)
	{
		fra->colors[i] = color + gradient_offset;
		gradient_offset += 0; //needs a good offset for gradient. Niklas: red loops up and down, green increase to full, blue increase to halfway.
		i++;
	}
}

void	init_julia(t_fract *fra, int argc, char **argv)
{
	float	params[2];

	ft_atof(argc, argv, params);
	fra->cR = params[0];
	fra->ci = params[1];
}
