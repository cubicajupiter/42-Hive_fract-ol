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

typedef struct	s_fract {
	void	*fract_img;
	char	*pixel_ptr;
	int		bpp;
	int		l_len;
	int		endian;
	void	*mlx;
	void	*window;
}	t_fract;

int		main(void);
void	blit_pixel(t_data *img, int x, int y, int color);

#endif
