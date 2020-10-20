/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:39:27 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/10/20 03:33:38 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/fractol.h"

void	ft_julia_op(t_fractal *data, int x, int y)
{
	double tmp;

	data->c_r = -2 + (double)x / data->zoom;
	data->c_i = -2 + (double)y / data->zoom;
	data->z_r = data->c_r;
	data->z_i = data->c_i;
	data->it = 0;                                                                                                                                     
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4 && data->it < data->it_max)
	{
		tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i - 0.4;
		data->z_i = 2 * tmp * data->z_i + 0.6;
		data->it++;
	}
	if (data->it == data->it_max)
	{
		data->img_data[x + W * y] = 0;
	}
	else
	{
		data->img_data[x + W * y] = 0xFF0000 * data->it;
	}
}

void	ft_julia(t_fractal *data)
{
	int i;
	int j;

	i = 0;
	while (i < W)
		{
			j = 0;
			while (j < W)
			{
				ft_julia_op(data, j, i);
				j++;
			}
			i++;
		}
}