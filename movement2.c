/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:03:05 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/21 18:37:36 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	s2(t_game_data *game_data)
{
	move_counter(game_data);
	game_data->map->y = game_data->tab * game_data->map->sprites_size;
	game_data->map->x = game_data->i * game_data->map->sprites_size;
	draw_filled_square(game_data->map, 0x00ff00);
	game_data->tab++;
	game_data->map->y = game_data->tab * game_data->map->sprites_size;
	game_data->map->x = game_data->i * game_data->map->sprites_size;
	game_data->data->str[game_data->tab][game_data->i] = 'P';
	game_data->data->str[game_data->tab - 1][game_data->i] = '0';
}

int	s(t_game_data *game_data)
{
	if (game_data->data->str[game_data->tab + 1][game_data->i] == '1')
		return (0);
	if (game_data->data->str[game_data->tab + 1][game_data->i] == 'B')
	{
		ft_printf("You died !\n");
		game_completed(game_data);
	}
	if (game_data->data->str[game_data->tab + 1][game_data->i] == 'E')
	{
		if (game_data->colectibles->amount == 0)
		{
			ft_printf("You completed this level with %d mooves !\n",
				game_data->data->movement);
			game_completed(game_data);
		}
		else if (game_data->colectibles->amount != 0)
			ft_printf("You need to collect all the coins before leaving !\n");
		return (0);
	}
	s2(game_data);
	return (0);
}

void	w2(t_game_data *game_data)
{
	move_counter(game_data);
	game_data->map->y = game_data->tab * game_data->map->sprites_size;
	game_data->map->x = game_data->i * game_data->map->sprites_size;
	draw_filled_square(game_data->map, 0x00ff00);
	game_data->tab--;
	game_data->map->y = game_data->tab * game_data->map->sprites_size;
	game_data->map->x = game_data->i * game_data->map->sprites_size;
	game_data->data->str[game_data->tab][game_data->i] = 'P';
	game_data->data->str[game_data->tab + 1][game_data->i] = '0';
}

int	w(t_game_data *game_data)
{
	if (game_data->data->str[game_data->tab - 1][game_data->i] == '1')
		return (0);
	if (game_data->data->str[game_data->tab - 1][game_data->i] == 'B')
	{
		ft_printf("You died !\n");
		game_completed(game_data);
	}
	if (game_data->data->str[game_data->tab - 1][game_data->i] == 'E')
	{
		if (game_data->colectibles->amount == 0)
		{
			ft_printf("You completed this level with %d mooves !\n",
				game_data->data->movement);
			game_completed(game_data);
		}
		else if (game_data->colectibles->amount != 0)
			ft_printf("You need to collect all the coins before leaving !\n");
		return (0);
	}
	w2(game_data);
	return (0);
}
