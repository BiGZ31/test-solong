/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_complete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo  <lumontgo@student.42perpig>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:46:42 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/15 12:46:45 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_counter(t_game_data *game_data)
{
	char	*test;

	game_data->data->movement++;
	test = ft_itoa(game_data->data->movement);
	game_data->map->y = game_data->map->sprites_size * game_data->data->row + 4;
	game_data->map->x = 165;
	draw_filled_square(game_data->map, 0x000000);
	mlx_string_put(game_data->map->mlx_ptr, game_data->map->win_ptr,
		165, game_data->map->sprites_size * game_data->data->row
		+ game_data->map->sprites_size / 2, 0xFFFFFF,
		test);
	free(test);
}

void	free_allocated_memory(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->c)
	{
		free(data->str[i]);
		i++;
	}
	free(data->str);
	data->str = NULL;
	data->c = 0;
}

void	game_completed(t_game_data	*game_data)
{
	mlx_clear_window(game_data->map->mlx_ptr, game_data->map->win_ptr);
	mlx_destroy_window(game_data->map->mlx_ptr, game_data->map->win_ptr);
	mlx_destroy_display(game_data->map->mlx_ptr);
	free_allocated_memory(game_data->data);
	free(game_data->data->str);
	free(game_data->data);
	free(game_data->map->mlx_ptr);
	free(game_data->map);
	exit(0);
}
