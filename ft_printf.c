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

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base(int dec, int base, int up)
{
	int		len;
	char	*nbr;
	int		neg;

	neg = 0;
	len = 1;
	if (dec < 0)
		dec *= -1;
	while (ft_pow(base, len) - 1 < dec)
		len++;
	nbr = (char*)malloc(sizeof(char*) * len);
	nbr[len + neg] = '\0';
	while (len-- > 0)
	{
		if (!up)
			nbr[len + neg] = (dec % base) + (dec % base > 9 ? 'a' - 10 : '0');
		else
			nbr[len + neg] = (dec % base) + (dec % base > 9 ? 'A' - 10 : '0');
		dec = dec / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

void use_flag(t_flag flag, va_list ap)
{
	if (flag.type == 'd' || flag.type == 'i')
		ft_putnbr(va_arg(ap, int));
	if (flag.type == 'u')
		ft_putnbr(va_arg(ap, unsigned int));
	if (flag.type == 'o')
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned), 8, 0));
	if (flag.type == 'x')
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned), 16, 0));
	if (flag.type == 'X')
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned), 16, 1));
	if (flag.type == 'f')
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned), 16, 0));
	if (flag.type == 'F')
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned), 16, 1));
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
