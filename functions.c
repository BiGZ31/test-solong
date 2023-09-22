/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo  <lumontgo@student.42perpig>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:27:41 by lumontgo          #+#    #+#             */
/*   Updated: 2023/09/15 12:27:41 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strrev(char *str, int i, int n, int signe)
{
	while (i >= 0)
	{
		str[i] = (signe * (n % 10)) + 48;
		n = n / 10;
		i--;
	}
	if (signe == -1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		signe;
	int		len;

	signe = 1;
	len = 1;
	i = n;
	if (n < 0)
	{
		signe = -1;
		len = 2;
	}
	while (i / 10 != 0)
	{
		len++;
		i /= 10;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	str = ft_strrev(str, i, n, signe);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	temp = s;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
	s = temp;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;
	char	*cast;
	size_t	test;

	test = count * size;
	if (test / count != size)
		return (NULL);
	if (test == 0)
		return (malloc(0));
	r = malloc(count * size);
	if (r == NULL)
		return (NULL);
	cast = (char *) r;
	ft_bzero(cast, size * count);
	return (cast);
}
