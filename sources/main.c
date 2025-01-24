/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre <joandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:19:17 by joandre           #+#    #+#             */
/*   Updated: 2025/01/24 06:56:04 by joandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_all_struct(t_general_data *data)
{
	data->data_mlx = malloc(sizeof(t_mlx_data));
	data->player = malloc(sizeof(t_player));
	data->screen = malloc(sizeof(t_screen));
	data->player->incr_x = 0;
	data->player->incr_y = 0;
}

int	main(int ac, char *av[])
{
	t_general_data	*data;

	data = malloc(sizeof(t_general_data));
	ft_init_all_struct(data);
	if (ac < 2)
		return (0);
	if (!ft_valid_map(av[1], data))
		return (1);
	ft_init_window(data->data_mlx);
	ft_screen(data);
	ft_print_player(data);
	ft_configue_image(data);
	mlx_loop(data->data_mlx->mlx);
	return (0);
}
