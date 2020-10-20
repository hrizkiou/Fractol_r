/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:39:40 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/10/20 03:32:20 by hrizkiou         ###   ########.fr       */
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

int				ft_assign(t_fractal *data, char **av)
{
	if (ft_strcmp(av[1], "Mandelbrot"))
	{
		ft_mandelbrot(data);
	}
	else if (ft_strcmp(av[1], "Julia"))
	{
		ft_julia(data);
	}
	else if (ft_strcmp(av[1], "Autre")) 
	{
		/* code */
	}
	return (0);
}

void			ft_init(t_fractal *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, W, H, "Windows");
	data->img_ptr = mlx_new_image(data->mlx_ptr, W, H);
	data->img_data = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp, &data->size_l, &data->endian);
}

int				main(int ac, char **av)
{
	t_fractal	*data;
	data = (t_fractal*)malloc(sizeof(t_fractal));
	int i;
	int j;
	int count;
	double tmp;
	data->zoom = 100;
	data->it_max = 30;
	
	if (ac != 2)
		ft_error(0);
	if (strcmp(av[1],"Mandelbrot") == 0)
	{
		ft_init(data);
		ft_burningship(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_ptr, 0, 0);
		mlx_hook(data->mlx_win, 2, 0, key_hook, data);
		//ft_menu(data);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_error(0);
}
