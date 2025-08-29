#include "fractol.h"

int	init_mlx(t_fract *fra)
{
	fra->mlx_ptr = mlx_init();
	if (!fra->mlx_ptr)
		return (ERROR);
	fra->win_ptr = mlx_new_window(fra->mlx_ptr), W_WIDTH, W_HEIGHT, "Fract-ol");
	if (!fra->win_ptr)
		return (ERROR);
	return (SUCCESS);
}

int	init_fract(t_fract *f, int argc, char **argv)
{
	f->img = mlx_new_image(f->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!f->img)
		return (ERROR);
	f->px_ptr = mlx_get_data_addr(f->img, &f->bpp, &f->l_len, &f->e);
	if (!f->px_ptr)
		return (ERROR);
	if (ft_strncmp(argv[1], "mandel", 7))
		f->type = MANDEL;
	else if (ft_strncmp(argv[1], "julia", 6))
	{
		init_julia(f, argc - 2, argv);
		f->type = JULIA;
	}
	else if (ft_strncmp(argv[1], "ship", 5))
		f->type = SHIP;
	else
	{
		ft_putendl_fd("Choose type: mandel, julia, ship", 1);
		free(f->mlx_ptr);
		return (ERROR);
	}
	return (SUCCESS);
	f->bpp_to_px = fr->bpp / 8;
}

void	init_planar_values(t_fract *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->magnitude = (long double) MAX_MAGNITUDE;
	fract->c_offset = fract->magnitude / 2.;
	fract->x_scale = fract->magnitude / W_WIDTH;
	fract->y_scale = fract->magnitude / W_HEIGHT * -1;
	fract->y_zoom = fract->y_scale + fract->c_offset;
	fract->x_zoom = fract->x_scale - fract->c_offset;
}

// colors are inputted as unsigned integers, 
// either explicit HEX integers
// or you have a function that shifts bits around in an int directly
void	init_colors(t_fract *fra)
{
	int		i;
	int		color;
	int		gradient_offset;

	i = 0;
	color = 0xTTRRGGBB;
	#012840
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
