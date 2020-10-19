/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 01:27:23 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/10/19 04:53:45 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"

# define W 800
# define H 600

typedef struct		s_complex
{
	int				reel;
	int				imag;
	int				iteration;
}					t_complex;
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

void				ft_menu(t_fractal data);
void				ft_move(t_fractal *data);
void				ft_increase_z(t_fractal *data);
void				ft_decrease_z(t_fractal *data);
int					key_hook(int key, t_fractal *data);
void				transformation_color(int key, t_fractal *data);
void				ft_free(char **ptr);
int					free_data(t_fractal *data);
int					ft_return(char **ptr, char *str, int err);
void				ft_close(t_fractal *data);
#endif
