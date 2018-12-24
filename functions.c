#include "ft_printf.h"
#include "libft/includes/libft.h"

int					ft_cat_pro(char **dest, char *src)
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

char		*ft_itoa_base(int dec, int base, int up)
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

char			*ft_ftoa(float nbr, int afterpoint)
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
