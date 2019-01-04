/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:36:56 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/27 16:37:00 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_specifier_di(t_specifier spec, long long int nbr)
{
	char			*src;
	int				len;

	len = 0;
	if (nbr == 0 && spec.precision == -1)
		src = ft_strnew(0);
	else src = ft_itoa_ll(nbr);
	prec_zero(&src, spec.precision);
	if (spec.flag_p || spec.flag_s)
		set_plus(&src, spec);
	if (spec.flag_z && !spec.flag_m && !spec.precision)
		if ((int)ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	len = (int)ft_strlen(src);
	if (!spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putstr(src);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}

void				print_specifier_u(t_specifier spec, unsigned long long nbr)
{
	char			*src;
	int				len;

	len = 0;
	if (!nbr && spec.precision == -1)
		src = ft_strnew(0);
	else src = ft_itoa_ull(nbr);
	prec_zero(&src, spec.precision);
	if (spec.flag_p || spec.flag_s)
		set_plus(&src, spec);
	if (spec.flag_z && !spec.flag_m && !spec.precision)
		if ((int)ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	len = (int)ft_strlen(src);
	if (!spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putstr(src);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}

/*
**	TODO: fix case: value = 0 & precision = 0
*/

void				print_specifier_s(t_specifier spec, va_list ap)
{
	char			*src;
	int				len;

	len = 0;
	if (!(src = va_arg(ap, char*)))
	{
		ft_putstr("(null)");
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

void				print_specifier_x(t_specifier spec, unsigned long long nbr)
{
	char			*src;
	int				len;

	len = 0;
	if (!nbr && spec.precision == -1)
		src = ft_strnew(0);
	else src = ft_itoa_base_ull(nbr, 16, spec.type);
	prec_zero(&src, spec.precision);
	if (spec.flag_h && nbr)
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
