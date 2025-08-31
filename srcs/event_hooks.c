#include "fractol.h"

int		reso_iterator(t_fract *fract)
{
	static int		current_reso; //this doesnt zero betwn zooms...
	double			tmp_zR;
	int				i;

	i = 0;
	if (current_reso < MAX_ITERS)
		current_reso++;
	tmp_zR = 0.0;
	gen_fr(fract, current_reso, &tmp_zR, i);
	return (SUCCESS);
}

int		closebutton(t_fract *fract)
{
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	return (SUCCESS);
}

int		keys(int keysym, t_fract *fract)
{
	if (keysym == KEY_ESCAPE || keysym == 17)
		mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
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

