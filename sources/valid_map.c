/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquilami <rquilami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:00:19 by joandre           #+#    #+#             */
/*   Updated: 2025/01/27 09:14:16 by rquilami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	 if (!map)
        return;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	pos(char *file)
{
	int	i;
	int	fd;
	char *tmp;

	i = 0;
	fd = open(file, O_RDONLY);
	while ((tmp = get_next_line(fd)))
	{
		free(tmp);
		i++;
	}
	close(fd);
	return (i);
}

char	**ft_readmap(char *file)
{
	char	**map;
	int		fd;
	int lines;
	int		i;

	fd = open(file, O_RDONLY);
	lines = pos(file);
	if (fd < 0)
	{
		printf(RED"Error: file not found\n"RESET);
		exit(-1);
	}
	i = 0;
	map = malloc(sizeof(char *) * (lines + 2));
	while ((map[i] = get_next_line(fd)))
	{
		i++;
	}
	close(fd);
	return (map);
}

int	verify_conf_color(char *buffer, char c)
{
	int	i;
	int	sep;

	sep = 0;
	i = 0;
	if (buffer[i] != c)
		return (-1);
	if (buffer[i + 1] && buffer[i + 1] != ' ')
		return (-1);
	i += 2;
	while (buffer[i] && buffer[i] != ' ')
	{
		if ((!ft_isdigit(buffer[i]) && buffer[i] != ',' && buffer[i] != '\n')
			|| (buffer[i] == ',' && !ft_isdigit(buffer[i + 1])))
			return (-1);
		if (buffer[i] == ',' && ft_isdigit(buffer[i + 1]))
			sep++;
		i++;
	}
	if (sep == 2)
		return (0);
	else
		return (-1);
}

int	ft_verify_options_in_map(char **map)
{
	int		i;
	char	*alert;
	char	*alrt2;

	i = 0;
	alrt2 = RED "ERROR: the configuration the color it is not in order or not exist\n" RESET;
	alert = RED "ERROR: the confuigure texture it is not in order or if fault\n";
	if (ft_strcmp(map[0], "NO ./path_to_the_north_texture\n"))
		return (free_map(map), write(2, alert, ft_strlen(alert)), exit(-1), 1);
	if (ft_strcmp(map[1], "SO ./path_to_the_south_texture\n"))
		return (free_map(map), write(2, alert, ft_strlen(alert)), exit(-1), 1);
	if (ft_strcmp(map[2], "WE ./path_to_the_west_texture\n"))
		return ( free_map(map), write(2, alert, ft_strlen(alert)), exit(-1), 1);
	if (ft_strcmp(map[3], "EA ./path_to_the_east_texture\n"))
		return (free_map(map), write(2, alert, ft_strlen(alert)), exit(-1), 1);
	i = 4;
	while (map[i] && ft_strcmp(map[i], "\n") == 0)
		i++;
	if (verify_conf_color(map[i++], 'F') == -1)
		return (free_map(map), write(2, alrt2, ft_strlen(alrt2)), exit(-1), -1);
	if (verify_conf_color(map[i++], 'C') == -1)
		return (free_map(map), write(2, alrt2, ft_strlen(alrt2)), exit(-1), -1);
	while (map[i] && ft_strcmp(map[i], "\n"))
		i++;
	return (i);
}

int	ft_analitic_map(char **map, t_game *mapp)
{
	int		i;
	i = 0;
	i = ft_verify_options_in_map(map);
	if (map[i][0] == '\n')
		i++;
	if (ft_analizer_map(&map[i]))
		printf("Ivalid map\n");
	//ft_count_player(&map[i]);
	mapp->map = &map[i];
    //free_map(map);
	return (i);
}

int	ft_valid_map(char *name, t_game *mapp)
{
	int	i;
	i = 0;
	i = strlen(name);
	if (strcmp(&name[i - 4], ".cub") == 0)
	{
		ft_analitic_map(ft_readmap((name)), mapp);
		return (1);
	}
	return (printf(RED"ERROR: file is not a \".cub\" type\n"RESET), exit(-1), 0);
}


