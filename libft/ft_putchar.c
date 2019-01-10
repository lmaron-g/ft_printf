/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:57:47 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/23 21:57:49 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void				ft_putchar(char c)
{
	write(1, &c, 1);
	g_r++;
}

/*
static void			ft_putchar_unic_3(int c)
{
	unsigned char	simb;

	if (c <= 65535)
	{
		simb = 240 + c / 32768;
		write(1, &simb, 1);
		c %= 32768;
		simb = 128 + c / 4096;
		write(1, &simb, 1);
		c %= 4096;
		simb = 128 + c / 64;
		write(1, &simb, 1);
		simb = 128 + c % 64;
		write(1, &simb, 1);
		g_r += 4;
	}
}

static void			ft_putchar_unic_2(int c)
{
	unsigned char	simb;

	if (c <= 65535)
	{
		simb = 224 + c / 4096;
		write(1, &simb, 1);
		c %= 4096;
		simb = 128 + c / 64;
		write(1, &simb, 1);
		simb = 128 + c % 64;
		write(1, &simb, 1);
		g_r += 3;
	}
	else
		ft_putchar_unic_3(c);
}

void				ft_putchar(int c)
{
	unsigned char	simb;

	if (0 <= c && c <= 255)
	{
		simb = c;
		write(1, &simb, 1);
		g_r++;
	}
	else if (c <= 2047)
	{
		simb = 192 + c / 64;
		write(1, &simb, 1);
		simb = 128 + c % 64;
		write(1, &simb, 1);
		g_r += 2;
	}
	else 
		ft_putchar_unic_2(c);
}
*/