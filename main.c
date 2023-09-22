/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:09:02 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/22 16:41:43 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_row2(t_data *data, int i, int row_length)
{
	int	f;

	row_length = i - data->start;
	data->str[data->c] = (char *)malloc(sizeof(char) * (row_length + 1));
	f = 0;
	while (f < row_length)
	{
		data->str[data->c][f] = data->map[data->start + f];
		f++;
	}
	data->str[data->c][row_length] = '\0';
	data->str[++data->c] = NULL;
}

void	allocate_memory(t_data *data, int row_length)
{
	int	f;

	data->str[data->c] = (char *)malloc(sizeof(char) * (row_length + 1));
	f = 0;
	while (f < row_length)
	{
		data->str[data->c][f] = data->map[data->start + f];
		f++;
	}
	data->str[data->c][row_length] = '\0';
	data->c++;
}

void	fill_row(t_data *data)
{
	int	i;
	int	row_length;

	i = 0;
	data->str = (char **)malloc(sizeof(char *) * (data->row + 1));
	data->c = 0;
	data->start = 0;
	while (data->map[i])
	{
		if (data->map[i] == '\n')
		{
			row_length = i - data->start;
			allocate_memory(data, row_length);
			data->start = i + 1;
		}
		i++;
	}
	if (data->start < i)
		fill_row2(data, i, data->start);
}

void	main2(t_data *data, t_map *map, t_game_data *game_data)
{
	map->x = 0;
	map->y = 0;
	map_checker(data);
	map_draw(data, map, game_data);
	mlx_loop_hook(map->mlx_ptr, anim, &game_data);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 0,
		map->sprites_size * data->row + map->sprites_size
		/ 2, 0xFFFFFF, "Mouvement Count: ");
	data->movement = 0;
	mlx_key_hook(map->win_ptr, player_movement, &game_data);
	mlx_loop(map->mlx_ptr);
	game_completed(game_data);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_map		*map;
	t_game_data	game_data;

	if (ac == 2)
	{
		data = NULL;
		data = (t_data *) ft_calloc(sizeof(t_data), 1);
		map = (t_map *) malloc(sizeof(t_map));
		read_map(av[1], data);
		map->sprites_size = 32;
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr,
				map->sprites_size * data->len,
				map->sprites_size * (data->row + 1), "So_long");
		main2(data, map, &game_data);
	}
	return (0);
}
