/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 00:39:06 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/10/22 03:53:40 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/fractol.h"

void	ft_mandelbrot_op(t_fractal *data, int x, int y)
{
	double tmp;

	data->x1 = -5;
	data->y1 = -3;

	data->c_r = data->x1 + (double)x / data->zoom;
	data->c_i = data->y1 + (double)y / data->zoom;
	data->z_r = data->c_r;
	data->z_i = data->c_i;
	data->it = 0;                                                                                                                                     
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4 && data->it < data->it_max)
	{
		tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * tmp * data->z_i + data->c_i;
		data->it++;
	}
	if (data->it == data->it_max)
	{
		data->img_data[x + W * y] = 0;
	}
	else
	{
		data->img_data[x + W * y] = 265 * data->it;
	}
}

void	ft_mandelbrot(t_fractal *data)
{
	int i;
	int j;

	i = 0;
	while (i < W)
		{
			j = 0;
			while (j < W)
			{
				ft_mandelbrot_op(data, j, i);
				j++;
			}
			i++;
		}
	
}