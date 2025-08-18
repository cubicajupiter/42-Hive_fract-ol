/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:21:01 by jvalkama          #+#    #+#             */
/*   Updated: 2025/08/18 15:35:22 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	render(t_fract *fract)
{
	mlx_put_image_to_window(fract->mlx, fract->window, fract->fract_img, 0, 0);
}

//match iteration count with color: 25 is inside fractal, 0 is background, 1-24 means it diverged. The smaller the i, the faster it diverged.
void	blit_px_to_img(t_fract *fract) 
{
	char	*dst;
	int		color;

	color = fract->colors[fract->i];
	dst = fract->pixel_ptr + (fract->y * fract->l_len + fract->x * (fract->bpp / 8));
	*(unsigned int*)dst = color;
}
