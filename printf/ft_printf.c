/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo  <lumontgo@student.42perpig>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:42:16 by lumontgo          #+#    #+#             */
/*   Updated: 2023/02/19 19:42:16 by lumontgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put(const char *str, int byte, char c)
{
	int	i;
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (byte == '1')
	{
		i = 0;
		while (str[i])
		{
			count += write(1, &str[i], 1);
			i++;
		}
	}
	if (byte == '0')
		count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr(unsigned int n, int count, char c)
{
	if ((int) n == -2147483648 && c == 'y')
		return (count += write(1, "-2147483648", 11));
	if (n < 10)
	{
		c = n + '0';
		count += ft_put("nothing", '0', c);
	}
	else
	{
		count = ft_putnbr(n / 10, count, c);
		count += ft_put("nothing", '0', c = (n % 10) + 48);
	}
	return (count);
}

int	ft_puthex(unsigned long long int n, int maj, char x)
{
	char			*base;
	int				count;
	unsigned int	cast;

	count = 0;
	if (x == 'x')
	{
		if (maj == '0')
			base = "0123456789abcdef";
		if (maj == '1')
			base = "0123456789ABCDEF";
		cast = (unsigned int) n;
		if (cast >= 16)
			count = ft_puthex(cast / 16, maj, x);
		count += ft_put("nothing", '0', base[cast % 16]);
		return (count);
	}
	base = "0123456789abcdef";
	if (n >= 16)
		count = ft_puthex(n / 16, maj, x);
	count += ft_put("nothing", '0', base[n % 16]);
	return (count);
}

int	ft_parse_format(const char *str, va_list args, int count, int i)
{
	int	value;

	if (str[i] == 'd' || str[i] == 'i')
	{
		value = va_arg(args, int);
		if (value < 0 && value != -2147483648)
		{
			value = -value;
			count += write(1, "-", 1);
			count += ft_putnbr(value, 0, 'y');
		}
		else
			count += ft_putnbr(value, 0, 'y');
	}
	if (str[i] == 'u')
				count += ft_putnbr(va_arg(args, unsigned int), 0, 'n');
	if (str[i] == 'x')
		count += ft_puthex(va_arg(args, long long int), '0', 'x');
	if (str[i] == 'X')
		count += ft_puthex(va_arg(args, long long int), '1', 'x');
	if (str[i] == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_puthex(va_arg(args, long long int), '0', 'w');
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			if (str[i + 1] == 'c')
				count += ft_put("nothing", '0', (char)va_arg(args, int));
			if (str[i + 1] == 's')
				count += ft_put(va_arg(args, char *), '1', 'c');
			count = ft_parse_format(str, args, count, i + 1);
			i += 2;
		}	
		else
		{
			if (str[i] == '%' && str[i + 1] == '%')
				i++;
			count += ft_put("NULL", '0', str[i]);
			i++;
		}
	}
	return (count);
}
/*
int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	int		value;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			i++;
			if (str[i] == 'c')
				count += ft_put("nothing", '0', va_arg(args, int));
			if (str[i] == 's')
				count += ft_put(va_arg(args, char *), '1', 'c');
			if (str[i] == 'd' || str[i] == 'i')
			{
				value = va_arg(args, int);
				if (value < 0 && value != -2147483648)
				{
					value = -value;
					count += write(1, "-", 1);
					count += ft_putnbr(value, 0, 'y');
				}
				else
					count += ft_putnbr(value, 0, 'y');
			}
			if (str[i] == 'u')
				count += ft_putnbr(va_arg(args, unsigned int), 0, 'n');
			if (str[i] == 'x')
				count += ft_puthex(va_arg(args, long long int), '0', 'x');
			if (str[i] == 'X')
				count += ft_puthex(va_arg(args, long long int), '1', 'x');
			if (str[i] == 'p')
			{
				count += write(1, "0x", 2);
				count += ft_puthex(va_arg(args, long long int), '0', 'w');
			}
			i++;
		}
		else
		{
			if (str[i] == '%' && str[i + 1] == '%')
			i++;
			count += ft_put("NULL", '0', str[i]);
			i++;
		}
	}	
	va_end(args);
	return (count);
}
*/