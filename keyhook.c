/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 00:56:38 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/10/22 04:04:19 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/fractol.h"

int     key_hook(int key, t_fractal *data)
{
	if (key == 53)
		ft_close(data);
        if (key == 123) // left
        {
                ft_move(key, data);
        }
        if (key == 124) // right
                ft_move(key, data);
        // if (key == 125) // down
        // if (key == 128) // up
	return (0);
}

int     mouse_press_hook(int button, int x, int y, t_fractal *data)
{
        // if (button == 1)
        //         //
        // else if (button == 2)
        //         //
	return (0);
}

void    ft_close(t_fractal *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(0);
}

void    ft_menu(t_fractal *data)
{
        int i;
        int j;

        i = -1;
        while (++i < 300)
        {
                j = -1;
                while (++j < 300)
                        mlx_pixel_put(data->mlx_ptr, data->mlx_win, i, j, 51);
        }
        mlx_string_put(data->mlx_ptr, data->mlx_win, 5, 1,
                        0x008000, "        How to use !");
        mlx_string_put(data->mlx_ptr, data->mlx_win, 5, 40,
                        0xFFFFFF, "         (p & i)");
        mlx_string_put(data->mlx_ptr, data->mlx_win, 5, 80,
                        0xFFFFFF, "    <-left right move->");
        mlx_string_put(data->mlx_ptr, data->mlx_win, 5, 120,
                        0xFFFFFF, "      up & down move");
        mlx_string_put(data->mlx_ptr, data->mlx_win, 5, 160,
                        0xFFFFFF, "   W+ or S- to increase z");
        mlx_string_put(data->mlx_ptr, data->mlx_win, 5, 200,
                        0xFFFFFF, " R or G or B to change color");
        mlx_string_put(data->mlx_ptr, data->mlx_win, 5, 240,
                        0xFFFFFF, "    Escape to leave !");
}