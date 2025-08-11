/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:12:31 by jvalkama          #+#    #+#             */
/*   Updated: 2025/08/11 14:13:23 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_linux/mlx.h"

// METASKILLS: code completion vim default: CTRL+Y

int		main(void) //NEXT: add support for arguments, to handle fract type
{
	void		*mlx;
	void		*window;
	t_data		img;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "Fract-ol");
	img.image = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.image, &img.bpp, &img.l_len, &img.endian);
	blit_pixel(&img, x_pos, y_pos, color_hexval); // count proper values with another func
	mlx_put_image_to_window(mlx, window, img.image, 0, 0); // 0, 0 begins from upper left corner of window
	mlx_loop(mlx);

	return (0);
}

void	blit_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
