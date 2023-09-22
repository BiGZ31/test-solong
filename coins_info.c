/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo  <lumontgo@student.42perpig>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:08:12 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/15 13:08:12 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_coins(t_game_data *game_data)
{
	int	i;
	int	j;

	i = 0;
	game_data->colectibles->amount = 0;
	while (game_data->data->str[i])
	{
		j = 0;
		while (game_data->data->str[i][j])
		{
			if (game_data->data->str[i][j] == 'C')
				game_data->colectibles->amount++;
			j++;
		}
		i++;
	}
}

void	display_coins_message(t_game_data *game_data)
{
	if (game_data->colectibles->binarie == 0)
	{
		if (game_data->colectibles->amount == 0)
		{
			printf("You collected all the coins, get to the exit\n");
			game_data->colectibles->binarie = 1;
			return ;
		}
		printf("There is %d coins left, You need to collect them\n",
			game_data->colectibles->amount);
		game_data->colectibles->binarie = 1;
	}
}

void	coins_info(t_game_data *game_data)
{
	count_coins(game_data);
	display_coins_message(game_data);
}
