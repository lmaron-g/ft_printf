/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:25:56 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/27 16:25:59 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		find_flags(t_specifier *spec, char *src)
{
	int		i;

	i = 0;
	spec->flag_m = 0;
	spec->flag_p = 0;
	spec->flag_s = 0;
	spec->flag_h = 0;
	spec->flag_z = 0;
	while (is_flag(src[i]))
	{
		if (src[i] == '-')
			spec->flag_m = 1;
		if (src[i] == '+')
			spec->flag_p = 1;
		if (src[i] == ' ')
			spec->flag_s = 1;
		if (src[i] == '#')
			spec->flag_h = 1;
		if (src[i] == '0')
			spec->flag_z = 1;
		i++;
	}
}

int			find_width(char *src, va_list ap)
{
	int		i;

	i = 0;
	while (is_flag(src[i]))
		i++;
	if (src[i] == '*')
		return (va_arg(ap, int));
	if (ft_atoi(&src[i]))
		return (ft_atoi(&src[i]));
	return (0);
}

int			find_precision(char *src, va_list ap)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != '.' && !ft_isalpha(src[i]))
		i++;
	if (src[i++] == '.')
	{
		if (src[i] == '*')
			return (va_arg(ap, int));
		if (ft_atoi(&src[i]))
			return (ft_atoi(&src[i]));
	}
	return (0);
}

int			contains_lenght(const char *src, const char *sub)
{
	size_t	n;

	n = ft_strlen((char*)sub);
	while (*src && !is_type(*src))
		if (!ft_memcmp(src++, sub, n))
			return (1);
	return (0);
}

int			find_lenght(char *src)
{
	if (contains_lenght(src, "hh"))
		return (20);
	if (contains_lenght(src, "ll"))
		return (10);
	if (contains_lenght(src, "L"))
		return (3);
	if (contains_lenght(src, "h"))
		return (2);
	if (contains_lenght(src, "l"))
		return (1);
	return (0);
}
