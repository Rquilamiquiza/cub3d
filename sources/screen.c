/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre <joandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:58:58 by joandre           #+#    #+#             */
/*   Updated: 2025/01/23 20:50:30 by joandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_screen(t_general_data *data)
{
    int color_ceil;
    int color_floor;
    
    data->screen->x = 0;
    data->screen->y = 0;
    color_ceil = 0xB2FFFF;
    color_floor = 0x0000FF00;
    while (data->screen->y < HEIGTH)
    {
        while (data->screen->x < WIDTH)
        {
            if (data->screen->y < HEIGTH / 2)
                data->screen->color = color_ceil;
            else
                data->screen->color = color_floor;
            ft_mlx_pixel_put(data->data_mlx, data->screen->x, data->screen->y, data->screen->color);
            data->screen->x++;
        }
        data->screen->x = 0;
        data->screen->y++;
    }
}
