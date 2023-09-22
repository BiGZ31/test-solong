/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_squares.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo  <lumontgo@student.42perpig>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:06:53 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/15 12:07:08 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_filled_square(t_map *map, int color)
{
	int	x_end;
	int	y_end;
	int	i;
	int	j;

	i = map->x;
	x_end = map->x + map->sprites_size;
	y_end = map->y + map->sprites_size;
	while (i < x_end)
	{
		j = map->y;
		while (j < y_end)
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_small_square(t_map *map, int color)
{
	int	x_end;
	int	y_end;
	int	i;
	int	j;

	x_end = map->x + 16;
	y_end = map->y + 16;
	i = map->x;
	while (i < x_end)
	{
		j = map->y;
		while (j < y_end)
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, i + 8, j + 8, color);
			j++;
		}
		i++;
	}
}

void	draw_medium_square(t_map *map, int color)
{
	int	x_end;
	int	y_end;
	int	i;
	int	j;

	x_end = map->x + 24;
	y_end = map->y + 24;
	i = map->x;
	color++;
	while (i < x_end)
	{
		j = map->y;
		while (j < y_end)
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, i + 4, j + 4, 0x0000ff);
			j++;
		}
		i++;
	}
}
