#include "fractol.h"

int		handle_no_event(void *fract)
{
	static int		max_reso;

	
	//loop hook could benefit from some updating
	//system loops let's say 5 iterations at once, repeating 10 times, enhancing the resolution.
	//cutoff from fractal loop after total 50 iterations, for example.
	//then loop handle_no_event until zoom, at which point another 50 for resolution.
	//
	return (0);
}

int		close_window(void *fract)
{
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	return (0);
}

int		handle_keypress(int keysym, t_struct *fract)
{
	if (keysym = XK_Escape || keysym = 17)
		mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	return (0);
}

int		mouse_scroll(int button, int x, int y, void *param);
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
	return (0);
}

