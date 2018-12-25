#include "libft/includes/libft.h"
#include "ft_printf.h"

void				print_specifier_di(t_specifier spec, long long int nbr)
{
	char			*src;
	int				len;

	len = 0;

	src = ft_itoa_ll(nbr);
	if (spec.precision)
		src[spec.precision] = '\0';
	if (spec.flag_p || spec.flag_s)
		set_plus(&src, spec.flag_s, spec.flag_p);
	if (spec.width)
		len = ft_strlen(src);
	if (!spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
	if (spec.flag_z && !spec.flag_m)
		while (len++ < spec.width)
			ft_putchar('0');
	ft_putstr(src);
	if (spec.flag_m)
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
	if (!spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putstr(src);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}

void		print_specifier_c(t_specifier spec, va_list ap)
{
	char	c;
	int 	len;

	len = 1;
	c = va_arg(ap, int);
	if (!spec.flag_m && spec.width)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putchar(c);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}
