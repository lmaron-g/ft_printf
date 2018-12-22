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
#include <unistd.h>
#include "ft_printf.h"

void use_flag(t_flag flag, va_list ap)
{
	if (flag.type == 'd')
		ft_putnbr(va_arg(ap, int));
	if (flag.type == 'c')
		ft_putchar(va_arg(ap, int));
	if (flag.type == 's')
		ft_putstr(va_arg(ap, char*));
}

int 		scan_flag(char *src, va_list ap)
{
	int		i;
	t_flag	flag;

	i = 0;
	while (src[i] && !ft_isalpha(src[i]))
	{
		i++;
	}
	if (ft_isalpha(src[i]))
	{
		flag.type = src[i];
		use_flag(flag, ap);
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
			i += scan_flag(&src[i + 1], ap);
		else
			ft_putchar(src[i]);
		i++;
	}
}
