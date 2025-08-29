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
# include "libft/libft.h"
# include <X11/X.h>

# define MAX_MAGNITUDE	4
# define ZOOM			1.3
# define W_WIDTH		1000
# define W_HEIGHT		1000
# define MAX_ITERS		250
# define ERROR			1
# define SUCCESS		0
# define INDEX			0
# define SCROLL_UP		4
# define SCROLL_DWN		5
# define LEFT_CLICK		1
# define RIGHT_CLICK	3
# define REDCROSS		17

typedef struct	s_fract {
	void			*img;
	char			*px_ptr;
	int				x;
	int				y;
	long double		zR;
	long double		zi;
	long double		cR;
	long double		ci;
	long double		x_scale;
	long double		y_scale;
	long double		magnitude;
	long double		offset;
	long double		y_zoom;
	long double		x_zoom;
	int				colors[MAX_ITERS];
	int				i;
	int				bpp;
	int				bpp_to_px;
	int				l_len;
	int				e;
	void			*mlx;
	void			*window;
	int				type;
}	t_fract;

//main.c
int		main(int argc, char *argv[]);
void	initialize(t_fract *fract);

//renderer.c
void	render(t_fract *fract);
void	blit_px_to_img(t_fract *fract, int i);

//fractal_generator.c
int		gen_fr(t_fract *restrict f, int re, double *restrict tmp_zR, int i);
static void	gen_m(t_fract *restrict fr, int re, int i, double *restrict tmp_zR);
static void	gen_j(t_fract *restrict fr, int re, int i, double *restrict tmp_zR);
static void	gen_s(t_fract *restrict fr, int re, int i, double *restrict tmp_zR);

//event_hooks.c
int		reso_iterator(void *fract);
int		closebutton(void *fract);
int		keys(int keysym, t_fract *fract);
int		mousebutton(int button, int x, int y, void *param);

//utils.c
void	ft_atof(int argc, char **argv, float *parameters);
void	get_decimal(char *string, float *result, int i, int divisor);
void	zoom_in(t_fract *restrict fract, int x, int y);
void	zoom_out(t_fract *restrict fract, int x, int y);

//inits.c
void	init_mlx(t_fract *fract);
void	init_fract(t_fract *fra);
void	init_planar_values(t_fract *fract);
void	init_colors(t_fract *fract);
void	init_julia(t_fract *fract, int argc, char **argv);

#endif
