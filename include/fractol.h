/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 01:27:23 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/10/22 04:21:43 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"

# define W 600 //1920
# define H 600 // 1080

typedef struct		s_data
{
	int				x;
	int				y;
	int				color;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				size_l;
	int				endian;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	double			x1;
	double			y1;
	int				zoom;
	int				it;
	int				it_max;
}					t_fractal;
void			ft_init(t_fractal *data);
void			ft_mandelbrot(t_fractal *data);
void			ft_mandelbrot_op(t_fractal *data, int x, int y);

void			ft_julia(t_fractal *data);
void			ft_julia_op(t_fractal *data, int x, int y);

void			ft_burningship(t_fractal *data);
void			ft_burningship_op(t_fractal *data, int x, int y);

void			ft_tricorn(t_fractal *data);
void			ft_tricorn_op(t_fractal *data, int x, int y);


void    ft_menu(t_fractal *data);

void				ft_move(int	key, t_fractal *data);
void				ft_increase_z(t_fractal *data);
void				ft_decrease_z(t_fractal *data);
int					key_hook(int key, t_fractal *data);
int					mouse_press_hook(int button, int x, int y, t_fractal *data);
void				transformation_color(int key, t_fractal *data);
void				ft_free(char **ptr);
int					free_data(t_fractal *data);
int					ft_return(char **ptr, char *str, int err);
void				ft_close(t_fractal *data);
#endif
