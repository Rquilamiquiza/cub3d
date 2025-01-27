#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK 64
# define DEBUG 0
# define RESET "\033[0m"
# define RED "\033[31m"

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define PI 3.14159265359

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;

	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;

	bool		left_rotate;
	bool		right_rotate;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;

	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;

	char		**map;
}				t_game;

void			init_player(t_player *player);
int				key_release(int keycode, t_player *player);
int				key_press(int keycode, t_game *game);
void			move_player(t_player *player);
int				ft_valid_map(char *name, t_game *mapp);
int				ft_analizer_map(char **map);
#endif