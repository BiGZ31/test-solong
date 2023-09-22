/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_read_cut-map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo  <lumontgo@student.42perpig>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:08:41 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/15 12:08:41 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

void	cut_map(t_data *data)
{
	int	i;

	i = 0;
	data->row = 1;
	data->c = 0;
	while (data->map[i])
	{
		if (data->map[i] == '\n')
		{
			data->len = i;
			break ;
		}
		i++;
	}
	i = 0;
	while (data->map[i])
	{
		if (data->map[i] == '\n')
			data->row++;
		i++;
	}
	fill_row(data);
	return ;
}

//set map in char *map
void	read_map(char *str, t_data *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(str, O_RDONLY);
	i = read(fd, data->map, BUFFER_SIZE - 1);
	data->map[i] = '\0';
	close(fd);
	cut_map(data);
}

void	draw_map_tile(t_data *data, t_map *map, t_game_data *game_data,
		int i)
{
	if (data->str[i][map->j] == '1')
		draw_filled_square(map, 0xFF0000);
	else if (data->str[i][map->j] == '0')
		draw_filled_square(map, 0x00ff00);
	else if (data->str[i][map->j] == 'P')
	{
		draw_filled_square(map, 0x0000ff);
		game_data->tab = i;
		game_data->i = map->j;
	}
	else if (data->str[i][map->j] == 'B')
		draw_filled_square(map, 0xF9429E);
	else if (data->str[i][map->j] == 'C')
		draw_filled_square(map, 0xFFFF00);
	map->x += 32;
}

void	map_draw(t_data *data, t_map *map, t_game_data *game_data)
{
	int	i;

	i = 0;
	map->j = 0;
	while (data->str[i])
	{
		map->j = 0;
		map->x = 0;
		while (map->j < data->len)
		{
			draw_map_tile(data, map, game_data, i);
			map->j++;
		}
		map->y += 32;
		i++;
	}
}
