/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:27:56 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/27 16:28:00 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int					is_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' \
		|| c == 'X' || c == 'f' || c == 'c' || c == 's' || c == 'p')
		return (1);
	return (0);
}

int					ft_size(long long int nb)
{
	int				size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

int					ft_size_u(unsigned long long nb)
{
	int				size;

	size = 1;
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

unsigned long long	ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}
