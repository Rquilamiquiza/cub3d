/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquilami <rquilami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:09:40 by rquilami          #+#    #+#             */
/*   Updated: 2025/01/27 09:50:09 by rquilami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/cub3d.h"

void put_pixel(int x, int y, int color, t_game *game)
{
    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return;
    
    int index = y * game->size_line + x * game->bpp / 8;
    game->data[index] = color & 0xFF;
    game->data[index + 1] = (color >> 8) & 0xFF;
    game->data[index + 2] = (color >> 16) & 0xFF;
}

void clear_image(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
                put_pixel(x, y, 0, game);
                x++;
        }
        y++;
    }
}

void draw_square(int x, int y, int size, int color, t_game *game)
{
    int i;

    i = 0;
    while (i < size)
        (put_pixel(x + i, y, color, game), i++);
    i = 0;
    while (i < size)
        (put_pixel(x, y + i, color, game), i++);
    i = 0;
    while (i < size)
        (put_pixel(x + size, y + i, color, game), i++);
    i = 0;
    while (i < size)
        (put_pixel(x + i, y + size, color, game), i++);
}

void draw_map(t_game *game)
{
    char **map = game->map;
    int color = 0xB2FFFF;
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1')
                draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
            x++;
        }
        y++;
    }
}

float distance(float x, float y)
{
    return sqrt(x * x + y * y);
}

float fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
    float delta_x;
    float delta_y;
    float angle;
    float fix_dist;

    delta_x = x2 - x1;
    delta_y = y2 - y1;
    angle = atan2(delta_y, delta_x) - game->player.angle;
    fix_dist = distance(delta_x, delta_y) * cos(angle);
    return (fix_dist);
}

bool touch(float px, float py, t_game *game)
{
    int x;
    int y;

    x = px / BLOCK;
    y = py / BLOCK;
    if(game->map[y][x] == '1')
        return (true);
    return (false);
}

void init_game(t_game *game)
{
    init_player(&game->player);
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

void draw_line(t_player *player, t_game *game, float start_x, int i)
{
    float cos_angle = cos(start_x);
    float sin_angle = sin(start_x);
    float ray_x = player->x;
    float ray_y = player->y;

    while(!touch(ray_x, ray_y, game))
    {
        if(DEBUG)
            put_pixel(ray_x, ray_y, 0xB2FFFF, game);
        ray_x += cos_angle;
        ray_y += sin_angle;
    }
    if(!DEBUG)
    {
        float dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
        float height = (BLOCK / dist) * (WIDTH / 2);
        int start_y = (HEIGHT - height) / 2;
        int end = start_y + height;
        while(start_y < end)
            (put_pixel(i, start_y, 255, game), start_y++);
    }
}

int draw_loop(t_game *game)
{
    t_player *player = &game->player;
    move_player(player);
    clear_image(game);
    if(DEBUG)
    {
        draw_square(player->x, player->y, 10, 0xB2FFFF, game);
        draw_map(game);
    }
    float fraction = PI / 3 / WIDTH;
    float start_x = player->angle - PI / 6;
    int i = 0;
    while(i < WIDTH)
    {
        draw_line(player, game, start_x, i);
        start_x += fraction;
        i++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return 0;
}

int main(int ac, char **av)
{
    t_game game;

    if (ac < 2)
		return (0);
	if (!ft_valid_map(av[1], &game))
		return (1);
    init_game(&game);
    mlx_hook(game.win, 2, 1L<<0, key_press, &game);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);
    mlx_loop_hook(game.mlx, draw_loop, &game);
    mlx_loop(game.mlx);
    return 0;
}