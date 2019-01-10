/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:20:20 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/20 21:20:22 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		len;
	int		copycount;
	char	*rez;

	len = 0;
	copycount = 0;
	while (s1[len] != '\0')
		len++;
	rez = (char*)malloc(len + 1);
	if (rez == (char*)0)
		return ((char*)0);
	while (s1[copycount])
	{
		rez[copycount] = s1[copycount];
		copycount++;
	}
	rez[copycount] = '\0';
	return (rez);
}

wchar_t		*ft_unicode_strdup(wchar_t *s1)
{
	int		len;
	int		copycount;
	wchar_t	*rez;

	len = 0;
	copycount = 0;
	while (s1[len] != '\0')
		len++;
	if (!(rez = (wchar_t*)malloc(sizeof(wchar_t) * (len + 1))))
		return (0);
	while (s1[copycount])
	{
		rez[copycount] = s1[copycount];
		copycount++;
	}
	rez[copycount] = '\0';
	return (rez);
}
