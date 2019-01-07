/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diouxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:19:07 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 17:19:14 by lmaron-g         ###   ########.fr       */
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
	else
		src = ft_itoa_ll(nbr);
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

void				print_specifier_o(t_specifier spec, unsigned long long nbr)
{
	char			*src;
	int				len;

	len = 0;
	if (!nbr && spec.precision == -1 && !spec.flag_h)
		src = ft_strnew(0);
	else
		src = ft_itoa_base_ull(nbr, 8, spec.type);
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

void				print_specifier_u(t_specifier spec, unsigned long long nbr)
{
	char			*src;
	int				len;

	len = 0;
	if (!nbr && spec.precision == -1)
		src = ft_strnew(0);
	else
		src = ft_itoa_ull(nbr);
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

void				print_specifier_x(t_specifier spec, unsigned long long nbr)
{
	char			*src;
	int				len;

	len = 0;
	if (!nbr && spec.precision == -1)
		src = ft_strnew(0);
	else
		src = ft_itoa_base_ull(nbr, 16, spec.type);
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
