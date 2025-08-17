/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:14:05 by jvalkama          #+#    #+#             */
/*   Updated: 2025/08/11 15:25:02 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_linux/mlx.h"

# define W_WIDTH		1000
# define W_HEIGHT		1000
# define COLOR_ORBIT	0 // hex value for a stable orbit.
# define COLOR_1S		0 // nS are hex values for how many steps until divergence.
# define COLOR_2S		0
# define COLOR_3S		0
# define COLOR_4S		0
# define COLOR_5S		0
# define COLOR_6S		0

typedef struct	s_fract {
	void		*img;
	char		*px_ptr;
	int			x;
	int			y;
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	double		x_scale;
	double		y_scale;
	int			bpp;
	int			l_len;
	int			e;
	void		*mlx;
	void		*window;
}	t_fract;

int		main(void);
void	blit_pixel(t_data *img, int x, int y, int color);

#endif
