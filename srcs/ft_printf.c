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

#include "ft_printf.h"

void			use_specifier(t_specifier spec, va_list ap)
{
	if (spec.type == 'd' || spec.type == 'i')
		print_specifier_di(spec, use_lenght_for_di(spec, ap));
	if (spec.type == 'o')
		print_specifier_o(spec, use_lenght_for_uoxx(spec, ap));
	if (spec.type == 'u')
		print_specifier_u(spec, use_lenght_for_uoxx(spec, ap));
	if (spec.type == 'x' || spec.type == 'X')
		print_specifier_x(spec, use_lenght_for_uoxx(spec, ap));
	if (spec.type == 'f')
		print_specifier_f(spec, use_lenght_for_f(spec, ap));
	if (spec.type == 'c' || spec.type == '%')
		print_specifier_c(spec, ap);
	if (spec.type == 'p')
		print_specifier_p(spec, ap);
	if (spec.type == 's')
		print_specifier_s(spec, ap);
}

/*
**  spec.parameter = find_parameter(src);
*/

int				scan_specifier(char *src, va_list ap)
{
	int			i;
	t_specifier	spec;

	i = 0;
	find_flags(&spec, src);
	spec.width = find_width(src, ap);
	spec.length = find_lenght(src);
	spec.precision = find_precision(src, ap);
	while (src[i] && is_right(src[i]) && !is_type(src[i]))
		i++;
	if (!is_type(src[i]))
		return (0);
	spec.type = src[i];
	use_specifier(spec, ap);
	return (i + 1);
}

int				ft_printf(char *src, ...)
{
	int			i;
	va_list		ap;

	i = 0;
	g_r = 0;
	va_start(ap, src);
	while (src[i])
	{
		if (src[i] == '%')
			i += scan_specifier(&src[i + 1], ap);
		else
			ft_putchar(src[i]);
		i++;
	}
	return (g_r);
}
