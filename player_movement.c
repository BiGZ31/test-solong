/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:59:37 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/22 16:35:50 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_coins_info(t_game_data *game_data)
{
	game_data->colectibles->copy = game_data->colectibles->amount;
	coins_info(game_data);
	if (game_data->colectibles->copy != game_data->colectibles->amount)
		game_data->colectibles->binarie = 0;
}

void	find_player_position(t_game_data *game_data)
{
	game_data->tab = 0;
	while (game_data->data->str[game_data->tab])
	{
		game_data->i = 0;
		while (game_data->data->str[game_data->tab][game_data->i])
		{
			if (game_data->data->str[game_data->tab][game_data->i] == 'P')
				return ;
			game_data->i++;
		}
		game_data->tab++;
	}
}

int game_end(t_game_data *game_data)
{
	game_completed(game_data);
	return (0);
}

int	player_movement(int keycode, t_game_data *game_data)
{
	update_coins_info(game_data);
	find_player_position(game_data);
	mlx_hook(game_data->map->win_ptr, 17, 1L << 5, game_end, game_data);
	if (keycode == 65307)
		game_completed(game_data);
	else if (keycode == 100)
		d(game_data);
	else if (keycode == 119)
		w(game_data);
	else if (keycode == 97)
		a(game_data);
	else if (keycode == 115)
		s(game_data);
	return (0);
}
