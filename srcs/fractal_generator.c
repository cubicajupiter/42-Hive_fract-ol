#include <math.h>

void	generate_fractal(char *type_arg, t_fract *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->x_scale = 4 / W_WIDTH;
	fract->y_scale = 4 / W_HEIGHT * -1;
	if (ft_strncmp(type_arg, "mandel", 7))
		gen_mandel(fract);
	else if (ft_strncmp(type_arg, "julia", 6))
		gen_julia(fract);
	else if (ft_strncmp(type_arg, "ship", 5))
		gen_ship(fract);
	else
		write(1, "Choose type: mandel, julia, ship\n", 33);
	mlx_put_image_to_window(fract->mlx, fract->window, fract->fract_img, 0, 0);
}

void	gen_mandel(t_fract *fract)
{
	int		i;
	
	while (fract->y < W_HEIGHT)
	{
		fract->c_i = fract->y * fract->y_scale + 2.;
		while (fract->x < W_WIDTH)
		{
			fract->z_r = 0.0;
			fract->z_i = 0.0;
			fract->c_r = fract->x * fract->x_scale - 2.;
			i = 0;
			while (++i < 25)
			{
				fract->z_r = ;
				fract->z_i = ;
				if (a + b) //magnitude calculation for z
					break;
			}
			blit_px_to_img(fract, i);
			fract->x++;
		}
		fract->x = 0;
		fract->y++;
	}
}

void	gen_julia(t_fract *fract)
{
	
}

void	gen_ship(t_fract *fract)
{
	
}
