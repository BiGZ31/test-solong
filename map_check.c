/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:51:53 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/22 16:41:38 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_printf("Error, map incorect\n");
	exit(0);
}

void	map_checker2(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i])
	{
		if (data->str[i][data->len - 1] != '1')
			error();
		i++;
	}
}

int	map_checker3(t_data *data, int j)
{
	j = 0;
	while (data->str[data->row - 1][j])
	{
		if (data->str[data->row - 1][j] != '1')
			error();
		j++;
	}
	return (j);
}

void	map_checker(t_data *data)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (data->row <= 1)
		error();
	while (data->str[0][j])
	{
		if (data->str[0][j] != '1')
			error();
		j++;
	}
	map_checker3(data, j);
	while (data->str[i])
	{
		if (data->str[i][0] != '1')
			error();
		i++;
	}
	map_checker2(data);
}
