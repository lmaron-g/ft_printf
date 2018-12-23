#include "libft/includes/libft.h"
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

void		print_specifier_di(t_specifier spec, va_list ap)
{
	int 	len;
	int		nbr;

	len = 0;
	nbr = va_arg(ap, int);
	if (spec.width)
		while (ft_pow(10, len) - 1 < nbr)
			len++;
	if (len && len >= spec.width)
		ft_putnbr(nbr);
	else while (len++ < spec.width)
		ft_putstr(" ");
	ft_putnbr(nbr);
}
