/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hovers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre <joandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:39:52 by joandre           #+#    #+#             */
/*   Updated: 2025/01/23 15:25:33 by joandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_window(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}

int	ft_key_hook(int keycode, t_mlx_data *data)
{
	if (keycode == 65307 || keycode == 65307)
		ft_close_window(data);
	return (0);
}