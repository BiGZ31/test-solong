/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo  <lumontgo@student.42perpig>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:40:46 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/15 12:40:57 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim2(t_game_data *game_data)
{
	draw_filled_square(game_data->map, 0x00ff00);
	draw_medium_square(game_data->map, 0x0000ff);
}

int	anim(t_game_data *game_data)
{
	if (!game_data->data->frame)
		game_data->data->frame = 0;
	game_data->data->frame++;
	if (game_data->data->frame < 10000)
		anim2(game_data);
	if (game_data->data->frame > 10000)
	{
		draw_filled_square(game_data->map, 0x00ff00);
		draw_small_square(game_data->map, 0x0000ff);
	}
	if (game_data->data->frame > 20000)
	{
		draw_filled_square(game_data->map, 0x00ff00);
		draw_medium_square(game_data->map, 0x0000ff);
	}
	if (game_data->data->frame > 30000)
	{
		draw_filled_square(game_data->map, 0x00ff00);
		draw_filled_square(game_data->map, 0x0000ff);
	}
	if (game_data->data->frame > 40000)
		game_data->data->frame = 0;
	return (0);
}
