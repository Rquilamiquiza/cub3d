/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre <joandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:44:37 by joandre           #+#    #+#             */
/*   Updated: 2025/01/23 22:44:48 by joandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_h
# define WIDTH 1300
# define HEIGTH 1100
# define RED "\033[31m"
# define RESET "\033[0m"

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
}				t_mlx_data;

typedef struct s_data_screen
{
	int			x;
	int			y;
	int			color;
}				t_screen;

typedef struct s_data_player
{
	int			dir_x;
	int			dir_y;
	int			fov;
	int			dir;
	int			*pos;
	int			incr_x;
	int			incr_y;
	int			color;
}				t_player;

typedef struct s_data
{
	char		**map;
	t_mlx_data	*data_mlx;
	t_player	*player;
	t_screen	*screen;
}				t_general_data;

void			ft_init_window(t_mlx_data *data);
void			ft_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
void			ft_configue_image(t_general_data *data);
int				ft_close_window(t_mlx_data *data);
int				ft_key_hook(int keycode, t_mlx_data *data);
int				ft_mouse_key(int keycode, t_mlx_data *data);
int				ft_valid_map(char *name, t_general_data *mapp);
char			**ft_readmap(char *file);
int				ft_analizer_map(char **map);
void			ft_screen(t_general_data *data);
void			ft_print_player(t_general_data *data);
int				ft_move_player(int ctrl, t_general_data *data);
#endif