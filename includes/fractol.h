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

# define W_WIDTH		1000
# define W_HEIGHT		1000
# define MAX_ITERS		50
# define ERROR			1
# define INDEX			0

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

//main.c
int		main(int argc, char *argv[]);
void	initialize_tools(t_fract *fract);
void	init_mlx(t_fract *fract);
void	init_fract(t_fract *fra);
void	init_colors(t_fract *fract);

//renderer.c
void	render(t_fract *fract);
void	blit_px_to_img(t_fract *fract, int i);

//fractal_generator.c
int		gen_fract_type(int argc, char *argv[], t_fract *fract);
void	gen_mandel(t_fract *fr, int i, double *save_zR);
void	gen_julia(t_fract *fr, int i, double *save_zR);
void	gen_ship(t_fract *fr, int i, double *save_zR);

//utils.c
void	init_members(t_fract *fract);
void	init_julia(t_fract *fract, int argc, char **argv);
void	ft_atof(int argc, char **argv, float *parameters);
void	get_decimal(char *string, float *result, int i, int divisor);

//libft
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);


#endif
