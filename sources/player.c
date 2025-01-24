/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre <joandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:02:56 by joandre           #+#    #+#             */
/*   Updated: 2025/01/24 08:12:37 by joandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move_player(int keycode, t_general_data *data)
{
	if (keycode == 65307 || keycode == 65307)
		ft_close_window(data->data_mlx);
	if (keycode == 0x61) // 'A'
		data->player->incr_x -= 3;
	else if (keycode == 0x64) // 'D'
		data->player->incr_x += 3;
	else if (keycode == 0x77) // 'W'
		data->player->incr_y -= 3;
	else if (keycode == 0x7A) // 'Z'
		data->player->incr_y += 3;
	// printf("chegou\n");
	mlx_destroy_image(data->data_mlx->mlx, data->data_mlx->img);
	data->data_mlx->img = mlx_new_image(data->data_mlx->mlx, WIDTH, HEIGTH);
	data->data_mlx->addr = mlx_get_data_addr(data->data_mlx->img,
			&data->data_mlx->bits_per_pixel, &data->data_mlx->line_length,
			&data->data_mlx->endian);
	ft_screen(data);
	ft_print_player(data);
	mlx_put_image_to_window(data->data_mlx->mlx, data->data_mlx->win,
		data->data_mlx->img, 0, 0); // Re-renderiza a janela
	return (0);                                                                                  
		// Retorno que é exigido pelo mlx_key_hook
}

void	ft_print_player(t_general_data *data)
{
	int	x;
	int	y;

	y = data->player->incr_y;
	x = data->player->incr_x;
	data->player->color = 0x00FF0000;
	data->player->dir_x = 0;
	data->player->dir_y = 0;
	while (data->player->dir_y < 10)
	{
		data->player->dir_x = 0;
		while (data->player->dir_x < 10)
		{
			ft_mlx_pixel_put(data->data_mlx, (data->player->dir_x + x),
				data->player->dir_y + y, data->player->color);
			data->player->dir_x++;
		}
		data->player->dir_y++;
	}
}
