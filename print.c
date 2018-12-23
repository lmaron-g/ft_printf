#include "libft/includes/libft.h"
#include "ft_printf.h"

// void		print_specifier_di(t_specifier spec, va_list ap)
// {
// 	int 	len;
// 	int		nbr;
//
// 	len = 0;
// 	nbr = va_arg(ap, int);
// 	if (spec.width)
// 		while (ft_pow(10, len) - 1 < nbr)
// 			len++;
// 	while (len++ < spec.width)
// 		ft_putchar(' ');
// 	ft_putnbr(nbr);
// }


void		print_specifier_di(t_specifier spec, va_list ap)
{
	char	*src;
	int		len;
	int		nbr;

	len = 0;
	nbr = va_arg(ap, int);
	src = ft_itoa(nbr);
	if (spec.precision)
		src[spec.precision] = '\0';
	if (spec.width)
		len = ft_strlen(src);
	if (!spec.flag || spec.flag == ' ' || spec.flag == '+')
		while (len++ < spec.width)
			if (spec.flag == '+' && len == spec.width)
				ft_putchar('+');
			else ft_putchar(' ');
	if (spec.flag == '0')
		while (len++ < spec.width)
			ft_putchar('0');
	ft_putstr(src);
	if (spec.flag == '-')
		while (len++ < spec.width)
			ft_putchar(' ');
}

void		print_specifier_s(t_specifier spec, va_list ap)
{
	char	*src;
	int		len;

	len = 0;
	src = ft_strdup(va_arg(ap, char*));
	if (spec.precision)
		src[spec.precision] = '\0';
	if (spec.width)
		len = ft_strlen(src);
	if (!spec.flag)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putstr(src);
	if (spec.flag == '-')
		while (len++ < spec.width)
			ft_putchar(' ');
}

void		print_specifier_c(t_specifier spec, va_list ap)
{
	char	c;
	int 	len;

	len = 1;
	c = va_arg(ap, int);
	if (!spec.flag && spec.width)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putchar(c);
	if (spec.flag == '-')
		while (len++ < spec.width)
			ft_putchar(' ');
}
