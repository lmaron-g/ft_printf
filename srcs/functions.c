/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:05:58 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/27 16:06:02 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_cat_pro(char **dest, char *src)
{
	char				*ret;
	char				*fresh;
	char				*dst;

	ret = 0;
	dst = *dest;
	if (dst && src && (fresh = ft_strnew(ft_strlen(dst) + ft_strlen(src))))
	{
		ret = fresh;
		while (*dst)
			*fresh++ = (char)*dst++;
		while (*src)
			*fresh++ = (char)*src++;
	}
	else
		return (0);
	ft_strdel(dest);
	*dest = ret;
	return (1);
}

void					prec_zero(char **src, int precision)
{
	int					i;
	int					len;
	char				*new;

	i = 0;
	if (**src != '-')
		len = ft_strlen(*src);
	else len = ft_strlen(*src) - 1;
	if (precision && precision > len)
	{
		if (**src != '-')
		{
			new = (char*)malloc(sizeof(char) * precision + 1);
			ft_strcpy(&new[precision - len], *src);
		}
		else
		{
			new = (char*)malloc(sizeof(char) * precision + 2);
			new[i++] = '-';
			ft_strcpy(&new[precision + 1 - len], *src + 1);
		}
		while (len++ < precision)
			new[i++] = '0';
		ft_strdel(src);
		*src = new;
	}
}

void					add_zero(char **src, t_specifier spec)
{
	int					i;
	int					st;
	int					len;
	char				*new;

	i = 0;
	len = ft_strlen(*src);
	new = ft_strnew(spec.width);
	if (**src == '-' || **src == '+')
		*new = **src;
	if (**src == '0' && (*src)[1] == spec.type && spec.type)
		new = ft_strncpy(new, *src, 2);
	while (new[i])
		i++;
	st = i;
	while (len++ < spec.width)
		new[i++] = '0';
	ft_strcpy(&new[i], *src + st);
	ft_strdel(src);
	*src = new;
}

void					set_plus(char **src, t_specifier spec)
{
	char				*new;

	if (**src != '-' && spec.type != 'u')
	{
		new = (char*)malloc(sizeof(char) * ft_strlen(*src) + 2);
		if (spec.flag_p)
			new[0] = '+';
		else if (spec.flag_s)
			new[0] = ' ';
		ft_strcpy(&new[1], *src);
		ft_strdel(src);
		*src = new;
	}
}

void					set_pref(char **src, char type)
{
	int					i;
	char				*new;

	i = 0;
	new = (char*)malloc(sizeof(char) * ft_strlen(*src) + 3);
	new[i++] = '0';
	if (type == 'x' || type == 'X')
		new[i++] = type;
	ft_strcpy(&new[i], *src);
	ft_strdel(src);
	*src = new;
}
