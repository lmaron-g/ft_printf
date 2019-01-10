/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:18:51 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 17:18:54 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 				ft_put_unicode(wchar_t c)
{
	if (c < 0x80)
		ft_putchar(c);
	else if (c < 0x800)
	{
		ft_putchar(c >> 6 | 0xC0);
		ft_putchar((c & 0x3F) | 0x80);
	}
	else if (c < 0x10000)
	{
		ft_putchar(c >> 12 | 0xE0);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
	}
	else if (c < 0x110000)
	{
		ft_putchar(c >> 18 | 0xF0);
		ft_putchar(((c >> 12) & 0x3F) | 0x80);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
	}
}

void				ft_put_unicode_str(wchar_t *src)
{
	int 			i;

	i = 0;
	if (src)
	{
		while (src[i] != '\0')
		{
			ft_put_unicode(src[i]);
			i++;
		}
		ft_unicode_strdel(&src);
	}
}

int					ft_unicode_simblen(wchar_t c)
{
	int				len;

	len = 0;
	if (c < 0x80)
		len = 1;
	else if (c < 0x800)
		len = 2;
	else if (c < 0x10000)
		len = 3;
	else if (c < 0x110000)
		len = 4;
	return (len);
}

int					ft_unicode_strlen(wchar_t *src)
{
	int				i;
	int				len;

	i = 0;
	len = 0;
	while(src[i])
		len += ft_unicode_simblen(src[i++]);
	return (len);
}

wchar_t				*ft_unicode_precision(wchar_t *src, int precision)
{
	int				i;
	int				len;

	i = 0;
	len = 0;
	if (precision)
		while(src[i])
		{
			len += ft_unicode_simblen(src[i]);
			if (len > precision)
				src[i] = '\0';
			i++;
		}
	return (src);
}



void				print_specifier_S(t_specifier spec, va_list ap)
{
	wchar_t			*src;
	int				len;

	len = 0;
	if (!(src = va_arg(ap, wchar_t*)))
	{
		write(1, "(null)", 6);
		g_r += 6;
		return ;
	}
	src = ft_unicode_strdup(src);
	src = ft_unicode_precision(src, spec.precision);
	if (spec.precision == -1)
		src[0] = '\0';
	if (spec.width)
		len = ft_unicode_strlen(src);
	if (!spec.flag_minus)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_put_unicode_str(src);
	if (spec.flag_minus)
		while (len++ < spec.width)
			ft_putchar(' ');
}

void				print_specifier_C(t_specifier spec, va_list ap)
{
	wchar_t			c;
	int				len;

	c = va_arg(ap, wchar_t);
	len = ft_unicode_simblen(c);
	if (!spec.flag_minus && spec.width)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_put_unicode(c);
	if (spec.flag_minus)
		while (len++ < spec.width)
			ft_putchar(' ');
}
