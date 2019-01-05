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

long long int	use_lenght_for_di(t_specifier spec, va_list ap)
{
	if (spec.length == 1)
		return (va_arg(ap, long));
	if (spec.length == 10)
		return (va_arg(ap, long long));
	if (spec.length == 2)
		return ((short int)va_arg(ap, int));
	if (spec.length == 20)
		return ((char)va_arg(ap, int));
	return (va_arg(ap, int));
}

long long int	use_lenght_for_uoxx(t_specifier spec, va_list ap)
{
	if (spec.length == 1)
		return (va_arg(ap, unsigned long int));
	if (spec.length == 10)
		return (va_arg(ap, unsigned long long int));
	if (spec.length == 2)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (spec.length == 20)
		return ((unsigned char)va_arg(ap, unsigned int));
	return (va_arg(ap, unsigned int));
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
