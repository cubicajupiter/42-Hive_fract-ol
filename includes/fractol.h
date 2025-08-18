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

# include "../mlx_linux/mlx.h"

# define MANDEL			1
# define JULIA			2
# define SHIP			3
# define NONE			0
# define GALAX			1
# define CLOUD			2
# define VORTEX			3
# define ELECTRO		4
# define W_WIDTH		1000
# define W_HEIGHT		1000
# define MAX_ITERS		25
# define ERROR			1

typedef struct	s_fract {
	void		*img;
	char		*px_ptr;
	int			x;
	int			y;
	double		zR;
	double		zi;
	double		cR;
	double		ci;
	double		x_scale;
	double		y_scale;
	int			colors[MAX_ITERS];
	int			i;
	int			bpp;
	int			l_len;
	int			e;
	void		*mlx;
	void		*window;
}	t_fract;

int		main(int argc, char *argv[]);
void	initialize_tools(t_fract *fract);
void	init_mlx(t_fract *fract);
void	init_fract(t_fract *fra);
void	render(t_fract *fract);
void	blit_px_to_img(t_fract *img, int x, int y, int color);
void	generate_fractal(int type, t_fract *fract);
void	gen_mandel_px(t_fract *fract);
void	gen_julia_px(t_fract *fract);
void	gen_ship_px(t_fract *fract);

//libft
int		ft_strncmp();
int		ft_putends();


#endif
