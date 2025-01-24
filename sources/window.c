/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre <joandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:20:06 by joandre           #+#    #+#             */
/*   Updated: 2025/01/24 06:56:21 by joandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)pixel = color;
}

void	ft_init_window(t_mlx_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGTH, "cub3d");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}
void ft_configue_image(t_general_data *data)
{
	mlx_put_image_to_window(data->data_mlx->mlx, data->data_mlx->win, data->data_mlx->img, 0, 0);  // Re-renderiza a janela
	mlx_key_hook(data->data_mlx->win, ft_move_player, data);
	mlx_hook(data->data_mlx->win, 17, 0, ft_close_window, data->data_mlx);
}