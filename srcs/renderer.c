

void	render(t_fract *fract)
{
	mlx_put_image_to_window(fract->mlx, fract->window, fract->fract_img, 0, 0);
}

void	blit_px_to_img(t_fract *fract, int divergence) //match iteration count with color: 25 is black, less means it diverged. Smaller means it diverged fast.
{
	char	*dst;

	dst = fract->pixel_ptr + (fract->y * fract->l_len + fract->x * (fract->bpp / 8));
	*(unsigned int*)dst = color;
}
