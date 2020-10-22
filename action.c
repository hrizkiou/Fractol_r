/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:32:08 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/10/22 04:11:15 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/fractol.h"

void    ft_zoom_in(t_fractal *data, int x, int y)
{
    
}

void    ft_zoom_out(t_fractal *data, int x, int y)
{
    
}

void    ft_move(int key, t_fractal *data)
{
    int i;
    int j;

    i = 0;
    while (i < W)
    {
        j = 0;
        while (j < W)
        {
            if (key == 123)
            {
                printf("x: %f  y: %f\n", data->x1 + 0.9,data->y1 + 0.9);
            }
            else if (key == 124)
            {
                printf("x: %f  y: %f\n", data->x1 - 0.9,data->y1 - 0.9);
            }
            j++;
        }
        i++;
    }
}