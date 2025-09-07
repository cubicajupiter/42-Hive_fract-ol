#include "fractol.h"

int		reso_iterator(t_fract *fract)
{
	double		tmp_zR;
	int			i;
	int			mouse_x;
	int			mouse_y;

	i = 0;
	tmp_zR = 0.0;
	gen_fr(fract, &tmp_zR, i);
	mlx_mouse_get_pos(fract->mlx_ptr, fract->win_ptr, &mouse_x, &mouse_y);
	draw_cursor(fract, mouse_x, mouse_y, i);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img, 0, 0);
	return (SUCCESS);
}

int		closebutton(t_fract *fract)
{
	clean_program(fract);
	return (SUCCESS);
}

int		keys(int keysym, t_fract *fract)
{
	if (keysym == KEY_ESCAPE || keysym == 17)
		clean_program(fract);
	return (SUCCESS);
}

int		mousebuttons(int button, int x, int y, void *param)
{
	t_fract		*fract;

	fract = (t_fract *) param;
	if (x < W_WIDTH && y < W_HEIGHT && x > 0 && y > 0)
	{
		if (button == SCROLL_UP || button == LEFT_CLICK)
			zoom_in(fract, x, y);
		else if (button == SCROLL_DWN || button == RIGHT_CLICK)
			zoom_out(fract, x, y);
	}
	return (SUCCESS);
}

void	draw_cursor(t_fract *f, int x, int y, int i)
{
	if (y > 0 && y < W_HEIGHT && x > 0 && x < W_WIDTH)
	{
		while (i < W_HEIGHT)
		{
			f->px_int_ptr[(i * f->l_len / 4) + x] = 0x00000000;
			i++;
		}
		i = 0;
		while (i < W_WIDTH)
		{
			f->px_int_ptr[(y * f->l_len / 4) + i] = 0x00000000;
			i++;
		}
	}
}
