/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:39:40 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/10/17 04:29:56 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

static	int		ft_error(int code)
{
	if (code == 0)
		ft_putendl("Usage : Fractal[Nom_du_Fractals]\n\t\tFractals:\n\t\t\t-->Mandelbrot\n\n\t\t\t-->Julia\n\n\t\t\t-->Autre\n");
	exit(-1);
}

// int				free_data(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	if (data->coord)
// 	{
// 		while (i < data->y_len)
// 		{
// 			ft_memdel((void *)&data->coord[i]);
// 			i++;
// 		}
// 		free(data->coord);
// 	}
// 	return (0);
// }

int				ft_assign(char **av)
{
	if (ft_strcmp(av[1], "Mandelbrot"))
	{
		/* code */
	}
	else if (ft_strcmp(av[1], "Julia"))
	{
		/* code */
	}
	else if (ft_strcmp(av[1], "Autre")) 
	{
		/* code */
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_fractal	*data;
	data = (t_fractal*)malloc(sizeof(t_fractal));
	int i = 1;
	int j;
	int count;
	int tmp;
	data->x1 = -2.1;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->zoom = 200;
	data->it_max = 100;
	
	if (ac != 2)
		ft_error(0);
	if (strcmp(av[1],"Mandelbrot") == 0)
	{
		data->mlx_ptr = mlx_init();
		data->mlx_win = mlx_new_window(data->mlx_ptr, W, H, "Windows");
		data->img_ptr = mlx_new_image(data->mlx_ptr, W, H);
		data->img_data = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp, &data->size_l, &data->endian);

		int	xscale = 0.25 / W; 
    	int yscale = 0.45 / W; 
		while (data->y <= W)
		{
			while (data->x <= W)
			{
				data->c_r = data->x * xscale + (-1.75);
				data->c_i = data->y * yscale + (-0.25);
				data->z_r = 0;
				data->z_i = 0;
				while ((data->z_r * data->z_r + data->z_i * data->z_i < 4) && (count < data->it_max))
				{
					tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
					data->z_i = 2 * data->z_r * data->z_i + data->c_i;
					data->z_r = tmp;
					count++;
				}
				data->x++;
			}
			data->y++;
			printf("Z reel: %d\tZ img: %d\n", data->z_r, data->z_i);
		}
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_ptr, 0, 0);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_error(0);
}
