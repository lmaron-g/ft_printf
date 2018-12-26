#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdio.h>

int						ft_cat_pro(char **dest, char *src)
{
	char			*ret;
	char			*fresh;
	char			*dst;

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

static int				ft_size(long long int nb)
{
	int		size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static int				ft_size_u(unsigned long long nb)
{
	int		size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

void					add_zero(char **src, int precision)
{
	int				i;
	int				len;
	char			*new;

	i = 0;
	len = ft_strlen(*src);
	if (precision && precision > len)
	{
		if (**src != '-')
		{
			new = (char*)malloc(sizeof(char) * precision + 1);
			while (len++ < precision)
				new[i++] = '0';
			ft_strcpy(&new[i], *src);
			ft_strdel(src);
			*src = new;
		}
		else
		{
			new = (char*)malloc(sizeof(char) * precision + 2);
			new[i++] = '-';
			while (len++ < precision)
				new[i++] = '0';
			ft_strcpy(&new[i], *src  + 1);
			ft_strdel(src);
			*src = new;
		}
	}
}

char					*ft_itoa_ll(long long int nb)
{
	char	*str;
	long long int	nbr;
	int		i;

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
	if (nb < 0)
		str[0] = '-';
	nbr = nb;
	if (nbr < 0)
		nbr = -nbr;
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
	int		len;
	char	*nbr;
	int		neg;

	neg = 0;
	len = 1;
	if (dec < 0)
		dec *= -1;
	while (ft_pow(base, len) - 1 < dec)
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

char					*ft_itoa_base_ull(unsigned long long dec, int base, char x)
{
	int					len;
	char				*nbr;
	int					neg;

	neg = 0;
	len = 1;
	if (dec < 0)
		dec *= -1;
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

char					*ft_ftoa(float nbr, int afterpoint)
{
	char		*fstr;
	int			i_part;
	float		f_part;

	i_part = (int)nbr;
	f_part = nbr - (float)i_part;
	fstr = ft_itoa(i_part);
	if (afterpoint > 0)
	{
		ft_cat_pro(&fstr, ".");
		f_part *= ft_pow(10, afterpoint);
		ft_cat_pro(&fstr, ft_itoa((int)f_part));
	}
	return (fstr);
}
