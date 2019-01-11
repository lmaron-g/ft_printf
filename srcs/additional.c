/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:18:14 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 17:18:17 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*round_it(char *src)
{
	int				i;

	i = ft_strlen(src) - 1;
	if ('5' <= src[i] && src[i] <= '9')
	{
		src[i] = '\0';
		while (--i)
			if (src[i] == '9')
				src[i] = '0';
			else if ('0' <= src[i] && src[i] <= '8')
			{
				src[i]++;
				return (src);
			}
	}
	src[i] = '\0';
	return (src);
}

int					ft_nbrlen(long long int nb)
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

int					ft_nbrlen_u(unsigned long long nb)
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
