/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquilami <rquilami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:09:51 by rquilami          #+#    #+#             */
/*   Updated: 2025/01/27 09:49:35 by rquilami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include "../includes/cub3d.h"

int	ft_close_window(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}

void init_player(t_player *player)
{
    player->x = WIDTH / 2;
    player->y = HEIGHT / 2;
    player->angle = PI / 2;

    player->key_up = false;
    player->key_down = false;
    player->key_right = false;
    player->key_left = false;

    player->left_rotate = false;
    player->right_rotate = false;
}

int key_press(int keycode, t_game *game)
{
	if (keycode == 65307 || keycode == 65307)
		ft_close_window(game);
    if(keycode == W)
        game->player.key_up = true;
    if(keycode == S)
        game->player.key_down = true;
    if(keycode == A)
        game->player.key_left = true;
    if(keycode == D)
        game->player.key_right = true;
    if(keycode == LEFT)
        game->player.left_rotate = true;
    if(keycode == RIGHT)
        game->player.right_rotate = true;
    return 0;
}

int key_release(int keycode, t_player *player)
{
	if (keycode == 53)
    if(keycode == W)
        player->key_up = false;
    if(keycode == S)
        player->key_down = false;
    if(keycode == A)
        player->key_left = false;
    if(keycode == D)
        player->key_right = false;
    if(keycode == LEFT)
        player->left_rotate = false;
    if(keycode == RIGHT)
        player->right_rotate = false;
    return 0;
}

void move_player(t_player *player)
{
    int speed = 2;
    float angle_speed = 0.03;
    float cos_angle = cos(player->angle);
    float sin_angle = sin(player->angle);

    if (player->left_rotate)
        player->angle -= angle_speed;
    if (player->right_rotate)
        player->angle += angle_speed;
    if (player->angle > 2 * PI)
        player->angle = 0;
    if (player->angle < 0)
        player->angle = 2 * PI;

    if (player->key_up)
    {
        player->x += cos_angle * speed;
        player->y += sin_angle * speed;
    }
    if (player->key_down)
    {
        player->x -= cos_angle * speed;
        player->y -= sin_angle * speed;
    }
    if (player->key_left)
    {
        player->x += sin_angle * speed;
        player->y -= cos_angle * speed;
    }
    if (player->key_right)
    {
        player->x -= sin_angle * speed;
        player->y += cos_angle * speed;
    }
}
