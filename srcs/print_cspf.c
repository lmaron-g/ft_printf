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

void				print_specifier_f(t_specifier spec, long double nbr)
{
	char			*src;
	int				len;

	len = 0;
	if (spec.precision == -1)
		src = ft_ftoa(nbr, 0);
	else
		src = ft_ftoa(nbr, (!spec.precision) ? 6 : spec.precision);
	prec_zero(&src, spec.precision);
	if (!spec.flag_h && src[ft_strlen(src) - 1] == '.')
		src[ft_strlen(src) - 1] = '\0';
	if (spec.flag_p || spec.flag_s)
		set_plus(&src, spec);
	if (spec.flag_z && !spec.flag_m)
		if ((int)ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	len = ft_strlen(src);
	if (!spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putstr(src);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}

void				print_specifier_p(t_specifier spec, va_list ap)
{
	char			*src;
	int				len;

	src = va_arg(ap, char *);
	spec.precision = 0;
	src = ft_itoa_base_ull((unsigned long long)src, 16, 'x');
	spec.type = 'x';
	prec_zero(&src, spec.precision);
	set_pref(&src, spec.type);
	if (spec.flag_z && !spec.flag_m && !spec.precision)
		if ((int)ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	len = ft_strlen(src);
	if (!spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putstr(src);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}

void				print_specifier_s(t_specifier spec, va_list ap)
{
	char			*src;
	int				len;

	len = 0;
	if (!(src = va_arg(ap, char*)))
	{
		write(1, "(null)", 6);
		g_r += 6;
		return ;
	}
	src = ft_strdup(src);
	if (spec.precision > 0)
		src[spec.precision] = '\0';
	if (spec.precision == -1)
		src[0] = '\0';
	if (spec.width)
		len = ft_strlen(src);
	if (!spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putstr(src);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}

void				print_specifier_c(t_specifier spec, va_list ap)
{
	char			c;
	int				len;

	len = 1;
	c = va_arg(ap, int);
	if (spec.type == '%')
		c = '%';
	if (!spec.flag_m && spec.width)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putchar(c);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}
