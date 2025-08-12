

void	render(t_fract *fract)
{

	blit_to_img(fract, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(fract->mlx, fract->window, fract->fract_img, 0, 0);
}

void	blit_to_img(t_fract *fract, int x, int y, int color)
{
	char	*dst;

	dst = fract->pixel_ptr + (y * fract->l_len + x * (fract->bpp / 8));
	*(unsigned int*)dst = color;
}
