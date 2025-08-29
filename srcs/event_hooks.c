#include "fractol.h"

int		reso_iterator(void *fract)
{
	static int		current_reso; //this doesnt zero betwn zooms...
	double			*save_zR;
	int				i;

	i = 0;
	current_reso++;
	*save_zR = 0.0;
	gen_fr(&fract, current_reso, save_zR, i))
	return (SUCCESS);
}

int		closebutton(void *fract)
{
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	return (SUCCESS);
}

int		keys(int keysym, t_fract *fract)
{
	if (keysym = XK_Escape || keysym = 17)
		mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	return (SUCCESS);
}

int		mousebuttons(int button, int x, int y, void *param)
{
	t_fract		*fract;

	fract = (t_fract *) param;
	if (x < W_WIDTH && y < W_HEIGHT && x > 0 && Y > 0)
	{
		if (button == SCROLL_UP || button == LEFT_CLICK)
			zoom_in(fract, x, y);
		else if (button == SCROLL_DWN || button == RIGHT_CLICK)
			zoom_out(fract, x, y);
	}
	return (SUCCESS);
}

