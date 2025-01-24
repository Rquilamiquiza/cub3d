/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquilami <rquilami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:02:56 by joandre           #+#    #+#             */
/*   Updated: 2025/01/24 15:48:52 by rquilami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_draw_rotated_triangle(t_general_data *data, double cx, double cy, double angle);


int ft_move_player(int keycode, t_general_data *data)
{
    const double speed = 5.0;

    if (keycode == 65307)
        ft_close_window(data->data_mlx);

    if (keycode == 119)
	{//Movimentar para frente
        data->player->incr_x += cos(data->player->triangle_angle) * speed;
        data->player->incr_y += sin(data->player->triangle_angle) * speed;
    }
    else if (keycode == 115)
	{//Movimentar para trás
        data->player->incr_x -= cos(data->player->triangle_angle) * speed;
        data->player->incr_y -= sin(data->player->triangle_angle) * speed;
    }
	else if (keycode == 97)//Movimentar para a esquerda
        data->player->incr_x -= 3;
    else if (keycode == 100) //Movimentar para a direita
        data->player->incr_x += 3;
    else if (keycode == 65361)
	{ //Rotacionar para a esquerda
        data->player->triangle_angle -= (15.0 * M_PI / 180.0);
        if (data->player->triangle_angle < 0)
            data->player->triangle_angle += 2 * M_PI;
    }
    else if (keycode == 65363)
	{ //Rotacionar para a direita
        data->player->triangle_angle += (15.0 * M_PI / 180.0);
        if (data->player->triangle_angle >= 2 * M_PI)
            data->player->triangle_angle -= 2 * M_PI;
    }
    mlx_destroy_image(data->data_mlx->mlx, data->data_mlx->img);
    data->data_mlx->img = mlx_new_image(data->data_mlx->mlx, WIDTH, HEIGTH);
    data->data_mlx->addr = mlx_get_data_addr(data->data_mlx->img,
            &data->data_mlx->bits_per_pixel, &data->data_mlx->line_length,
            &data->data_mlx->endian);
    ft_screen(data);
    ft_draw_rotated_triangle(data, data->player->incr_x, data->player->incr_y, data->player->triangle_angle);

    mlx_put_image_to_window(data->data_mlx->mlx, data->data_mlx->win,
        data->data_mlx->img, 0, 0);
    return (0);
}

void ft_draw_line(t_general_data *data, double x1, double y1, double x2, double y2, int color)
{
	double dx = x2 - x1;
	double dy = y2 - y1;
	double steps;
	double x = x1;
	double y = y1;
	int i = 0;

	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	double x_increment = dx / steps;
	double y_increment = dy / steps;

	while (i <= steps)
	{
		ft_mlx_pixel_put(data->data_mlx, x, y, color);
		x += x_increment;
		y += y_increment;
		i++;
	}
}
void ft_rotate_point(double *x, double *y, double cx, double cy, double angle)
{
    double temp_x = *x;
    double temp_y = *y;

    *x = cx + (temp_x - cx) * cos(angle) - (temp_y - cy) * sin(angle);
    *y = cy + (temp_x - cx) * sin(angle) + (temp_y - cy) * cos(angle);
}

void	ft_print_player(t_general_data *data)
{
	int	start_x, end_x;
	int	y = data->player->incr_y;
	int	x = data->player->incr_x;

	data->player->color = 0x00FF0000;

	for (int dir_y = 10; dir_y < 20; dir_y++)
	{
		start_x = 10 - (dir_y - 10);
		end_x = 10 + (dir_y - 10);

		for (int dir_x = start_x; dir_x <= end_x; dir_x++)
		{
			ft_mlx_pixel_put(data->data_mlx, dir_x + x, dir_y + y, data->player->color);
		}
	}
}

void	ft_draw_rotated_triangle(t_general_data *data, double cx, double cy, double angle)
{
	double x1 = 10, y1 = 10;
	double x2 = 5, y2 = 20;
	double x3 = 15, y3 = 20;

	ft_rotate_point(&x1, &y1, 10, 15, angle);
	ft_rotate_point(&x2, &y2, 10, 15, angle);
	ft_rotate_point(&x3, &y3, 10, 15, angle);
	ft_draw_line(data, x1 + cx, y1 + cy, x2 + cx, y2 + cy, data->player->color);
	ft_draw_line(data, x2 + cx, y2 + cy, x3 + cx, y3 + cy, data->player->color);
	ft_draw_line(data, x3 + cx, y3 + cy, x1 + cx, y1 + cy, data->player->color);
}


