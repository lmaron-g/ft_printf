#include "libft/includes/libft.h"
#include "ft_printf.h"
#include <stdio.h>

void				print_specifier_di(t_specifier spec, long long int nbr)
{
	char			*src;
	int				len;

	len = 0;
	src = ft_itoa_ll(nbr);
	prec_zero(&src, spec.precision);
	if (spec.flag_p || spec.flag_s)
		set_plus(&src, spec.flag_s, spec.flag_p);
	if (spec.flag_z && !spec.flag_m && !spec.precision)
		if (ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	len = ft_strlen(src);
	if (!spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putstr(src);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}

void				print_specifier_u(t_specifier spec, unsigned long long nbr)
{
	char			*src;
	int				len;

	len = 0;
	src = ft_itoa_ull(nbr);
	prec_zero(&src, spec.precision);
	if (spec.flag_p || spec.flag_s)
		set_plus(&src, spec.flag_s, spec.flag_p);
	if (spec.flag_z && !spec.flag_m && !spec.precision)
		if (ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	len = ft_strlen(src);
	if (!spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putstr(src);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}

void				print_specifier_f(t_specifier spec, long double nbr)
{
	// char			*src;
	// int				len;
	//
	// len = 0;
	//
	// src = ft_ftoa(nbr);
	// add_zero(&src, spec.precision);
	// if (spec.flag_p || spec.flag_s)
	// 	set_plus(&src, spec.flag_s, spec.flag_p);
	// len = ft_strlen(src);
	// if (spec.flag_z && !spec.flag_m && !spec.precision)
	// 	while (len++ < spec.width)
	// 		ft_putchar('0');
	// if (!spec.flag_m )
	// 	while (len++ < spec.width)
	// 		ft_putchar(' ');
	// ft_putstr(src);
	// if (spec.flag_m)
	// 	while (len++ < spec.width)
	// 		ft_putchar(' ');
}

void				print_specifier_p(t_specifier spec, va_list ap)
{
	int 			len;
	char			*s;
	unsigned int	p;

	len = 2 * sizeof(p);
	s = (char*)malloc(len + 1);
	p = (unsigned int)va_arg(ap, void*);
	if (!spec.flag_m && spec.width)
		while (len++ < spec.width)
			ft_putchar(' ');
	len = 2 * sizeof(p);
	while (len--)
	{
		s[len] = "0123456789abcdef"[p & 0x0F];
		p >>= 4;
	}
	while (++len < 2 * sizeof(p))
		ft_putchar(s[len]);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}

void				print_specifier_s(t_specifier spec, va_list ap)
{
	char			*src;
	int				len;

	len = 0;
	src = va_arg(ap, char*);
	if (!src)
	{
		ft_putstr("(null)");
		return ;
	}
	src = ft_strdup(src);
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

void				print_specifier_c(t_specifier spec, va_list ap)
{
	char			c;
	int 			len;

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

void				print_specifier_x(t_specifier spec, unsigned long long nbr)
{
	char			*src;
	int				len;

	len = 0;
	src = ft_itoa_base_ull(nbr, 16, spec.type);
	prec_zero(&src, spec.precision);
	if (spec.flag_h)
		set_pref(&src, spec.type);
	if (spec.flag_z && !spec.flag_m && !spec.precision)
		if (ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	len = ft_strlen(src);
	if (!spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putstr(src);
	if (spec.flag_m)
		while (len++ < spec.width)
			ft_putchar(' ');
}
