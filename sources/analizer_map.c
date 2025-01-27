/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analizer_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquilami <rquilami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:38:25 by joandre           #+#    #+#             */
/*   Updated: 2025/01/27 09:21:38 by rquilami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_tab_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_opt_map(char c)
{
	const char	*string = "NSEW";

	return (ft_strchr(string, c) != NULL);
}

// Verifica se a linha do topo ou base do mapa é válida
int	ft_top_down_map(char *map)
{
	int	j;

	j = 0;
	if (!map)
		return (-1);
	while (ft_tab_space(map[j]))
		j++;
	if (map[j] != '1')
		return (-1);
	while (map[j] && map[j] != '\n')
	{
		if (map[j] != '1' && map[j] != ' ')
			return (printf("passou"), -1);
		j++;
	}
	return (0);
}

// Verifica se o corpo do mapa é válido
int	ft_body_map(char *map, char **full_map, int y)
{
	int	x;

	x = 0;
	if (!map || !full_map)
		return (-1);
	while (map[x] && ft_tab_space(map[x]))
		x++;
	if (map[x] != '1')
		return (-1);
	while (map[x] && map[x] != '\n')
	{
		if (map[x] == '0')
		{
			if (ft_tab_space(full_map[y - 1][x]) || ft_tab_space(full_map[y
					+ 1][x]))
				return (-1);
		}
		else if (ft_tab_space(map[x]) && map[x + 1] == '0')
			return (-1);
		if (map[x] != '1' && map[x] != '0' && !ft_tab_space(map[x])
			&& !ft_opt_map(map[x]))
			return (-1);
		x++;
	}
	return (0);
}

int	ft_c_matrix(char **mat)
{
	int	i;

	if (!mat)
		return (0);
	i = 0;
	while (mat[i])
		i++;
	return (i);
}

int	ft_count_player(char  **map)
{
	int	x;
	int	y;
	int	count_player;

	count_player = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (ft_opt_map(map[y][x]))
			{
				count_player++;
				if (count_player > 1)
					return (ft_putstr_fd("ERROR: More than one player in the map\n",
							2), exit(-1), -1);
			}
			x++;
		}
		y++;
	}
	if (count_player < 1)
		return (ft_putstr_fd("ERROR: no player in the map\n", 2),
			exit(-1), -1);
			return (0);
}

// Função principal para validar o mapa completo
int	ft_analizer_map(char **map)
{
	int	y;
	int	total_lines;

	if (!map)
		return (-1);
	total_lines = ft_c_matrix(map);
	if (!total_lines)
		return (-1);
	if (!ft_strchr(map[total_lines - 1], '1'))
		return (-1);
	y = 0;
	while (map[y])
	{
		if (y == 0 || y == total_lines - 1)
		{
			if (ft_top_down_map(map[y]) == -1)
				return (-1);
		}
		else
		{
			if (ft_body_map(map[y], map, y) == -1)
				return (-1);
		}
		y++;
	}
	return (0);
}
