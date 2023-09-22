/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:55:08 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/22 16:41:51 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE	1024

typedef struct s_data
{
	char			**str;
	char			map[BUFFER_SIZE];
	int				len;
	int				row;
	int				c;
	int				start;
	int				movement;
	int				frame;
	char			*test;
	struct s_data	*fill;
}				t_data;

typedef struct s_map
{
	int				sprites_size;
	int				x;
	int				y;
	int				j;
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_map	*bomb;
}				t_map;

typedef struct s_colectibles
{
	int	amount;
	int	copy;
	int	binarie;
}				t_colectibles;

typedef struct s_game_data {
	int				tab;
	int				i;
	t_map			*map;
	t_data			*data;
	t_colectibles	*colectibles;
}	t_game_data;

int				d(t_game_data *game_data);
int				w(t_game_data *game_data);
int				a(t_game_data *game_data);
int				s(t_game_data *game_data);
int				ft_strlen(char *str);
int				player_movement(int keycode, t_game_data *game_data);
int				anim(t_game_data *game_data);
void			draw_filled_square(t_map *map, int color);
void			draw_small_square(t_map *map, int color);
void			draw_medium_square(t_map *map, int color);
void			map_checker(t_data *data);
void			fill_row(t_data *data);
void			cut_map(t_data *data);
void			read_map(char *str, t_data *data);
void			map_draw(t_data *data, t_map *map, t_game_data *game_data);
void			coins_info(t_game_data *game_data);
void			move_counter(t_game_data *game_data);
void			game_completed(t_game_data	*game_data);
void			free_allocated_memory(t_data *data);
void			*ft_calloc(size_t count, size_t size);
char			*ft_itoa(int n);

#endif
