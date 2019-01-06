/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:19:04 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/27 16:19:10 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_itoa_ll(long long int nb)
{
	char				*str;
	long long int		nbr;
	int					i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_size(nb) + 1)))
		return (NULL);
	if (nb < 0)
		str[0] = '-';
	nbr = nb;
	if (nbr < 0)
		nbr = -nbr;
	str[ft_size(nb) - i++] = '\0';
	while (nbr >= 10)
	{
		str[ft_size(nb) - i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[ft_size(nb) - i++] = (nbr % 10) + 48;
	return (str);
}

char					*ft_itoa_ull(unsigned long long nb)
{
	char				*str;
	unsigned long long	nbr;
	int					i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_size_u(nb) + 1)))
		return (NULL);
	nbr = nb;
	str[ft_size_u(nb) - i++] = '\0';
	while (nbr >= 10)
	{
		str[ft_size_u(nb) - i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[ft_size_u(nb) - i++] = (nbr % 10) + 48;
	return (str);
}

char					*ft_itoa_base(int dec, int base, int up)
{
	int					len;
	char				*nbr;
	int					neg;

	neg = 0;
	len = 1;
	if (dec < 0)
		dec *= -1;
	while ((int)ft_pow(base, len) - 1 < dec)
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

char					*ft_itoa_base_ull(unsigned long long dec,
															int base, char x)
{
	int					len;
	char				*nbr;
	int					neg;

	neg = 0;
	len = 1;
	while (ft_pow(base, len) - 1 < dec)
		len++;
	nbr = (char*)malloc(sizeof(char*) * len);
	nbr[len + neg] = '\0';
	while (len-- > 0)
	{
		if (x == 'x')
			nbr[len + neg] = (dec % base) + (dec % base > 9 ? 'a' - 10 : '0');
		else
			nbr[len + neg] = (dec % base) + (dec % base > 9 ? 'A' - 10 : '0');
		dec = dec / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

char					*ft_ftoa(long double nbr, int afterpoint)
{
	char				*src;
	char				trans;
	int					i;
	int					j;

	src = (char*)malloc(sizeof(char) * afterpoint);
	i = afterpoint + 1;
	if (nbr < 0 && !(j = 0))
	{
		nbr = -nbr;
		src[j++] = '-';
	}
	while ((int)nbr > 10 && ++i)
		nbr /= (long double)10.0;
	while (i-- > 0)
	{
		trans = (int)nbr;
		src[j++] = trans | 0x30;
		if (i == afterpoint)
			src[j++] = '.';
		nbr -= (double)trans;
		nbr *= 10.0;
	}
	src[j++] = '\0';
	return (src);
}
