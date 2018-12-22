/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:12:21 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/21 22:12:24 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

void use_specifier(t_specifier spec, va_list ap)
{
	if (spec.type == 'd' || spec.type == 'i')
		ft_putnbr(va_arg(ap, int));
	if (spec.type == 'u')
		ft_putnbr(va_arg(ap, unsigned int));
	if (spec.type == 'o')
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned), 8, 0));
	if (spec.type == 'x')
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned), 16, 0));
	if (spec.type == 'X')
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned), 16, 1));
	if (spec.type == 'f')
		ft_putstr(ft_ftoa((float)va_arg(ap, double), 6));
	if (spec.type == 'c')
		ft_putchar(va_arg(ap, int));
	if (spec.type == 's')
		ft_putstr(va_arg(ap, char*));
}

int 		scan_specifier(char *src, va_list ap)
{
	int		i;
	t_specifier	spec;

	i = 0;
	while (src[i] && !ft_isalpha(src[i]))
	{
		i++;
	}
	if (ft_isalpha(src[i]))
	{
		spec.type = src[i];
		use_specifier(spec, ap);
		return (i + 1);
	}
	return (0);
}

void	ft_printf(char *src, ...)
{
	int	i;
	va_list ap;

	i = 0;
	va_start(ap, src);
	while (src[i])
	{
		if (src[i] == '%')
			i += scan_specifier(&src[i + 1], ap);
		else
			ft_putchar(src[i]);
		i++;
	}
}
