/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:58:14 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/03 13:58:16 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_specifier_f(t_specifier spec, long double nbr)
{
	char			*src;
	int				len;

	len = 0;
	src = ft_ftoa(nbr, 6);
	add_zero(&src, spec);
	if (spec.flag_p || spec.flag_s)
		set_plus(&src, spec.flag_s, spec.flag_p);
	len = ft_strlen(src);
	if (spec.flag_z && !spec.flag_m && !spec.precision)
		while (len++ < spec.width)
			ft_putchar('0');
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
	int				len;
	char			*s;
	unsigned int	p;

	len = 2 * sizeof(p);
	s = (char*)malloc(len + 1);
	p = (unsigned int)va_arg(ap, void*);
	if (!spec.flag_m && spec.width)
		while (len++ < spec.width)
			ft_putchar(' ');
	len = 2 * (int)sizeof(p);
	while (len--)
	{
		s[len] = "0123456789abcdef"[p & 0x0F];
		p >>= 4;
	}
	while (++len < 2 * (int)sizeof(p))
		ft_putchar(s[len]);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}
