/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:48:45 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/21 18:37:35 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	d2(t_game_data *game_data)
{
	move_counter(game_data);
	game_data->map->y = game_data->tab * game_data->map->sprites_size;
	game_data->map->x = game_data->i * game_data->map->sprites_size;
	draw_filled_square(game_data->map, 0x00ff00);
	game_data->i++;
	game_data->map->y = game_data->tab * game_data->map->sprites_size;
	game_data->map->x = game_data->i * game_data->map->sprites_size;
	game_data->data->str[game_data->tab][game_data->i] = 'P';
	game_data->data->str[game_data->tab][game_data->i - 1] = '0';
}

int	d(t_game_data *game_data)
{
	if (game_data->data->str[game_data->tab][game_data->i + 1] == '1')
		return (0);
	if (game_data->data->str[game_data->tab][game_data->i + 1] == 'B')
	{
		ft_printf("You died !\n");
		game_completed(game_data);
	}
	if (game_data->data->str[game_data->tab][game_data->i + 1] == 'E')
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
	d2(game_data);
	return (0);
}

void	a2(t_game_data *game_data)
{
	move_counter(game_data);
	game_data->map->y = game_data->tab * game_data->map->sprites_size;
	game_data->map->x = game_data->i * game_data->map->sprites_size;
	draw_filled_square(game_data->map, 0x00ff00);
	game_data->i--;
	game_data->map->y = game_data->tab * game_data->map->sprites_size;
	game_data->map->x = game_data->i * game_data->map->sprites_size;
	game_data->data->str[game_data->tab][game_data->i] = 'P';
	game_data->data->str[game_data->tab][game_data->i + 1] = '0';
}

int	a(t_game_data *game_data)
{
	if (game_data->data->str[game_data->tab][game_data->i - 1] == '1')
		return (0);
	if (game_data->data->str[game_data->tab][game_data->i - 1] == 'B')
	{
		ft_printf("You died !\n");
		game_completed(game_data);
	}
	if (game_data->data->str[game_data->tab][game_data->i - 1] == 'E')
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
	a2(game_data);
	return (0);
}
