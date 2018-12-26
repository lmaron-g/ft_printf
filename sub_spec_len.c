#include "libft/includes/libft.h"
#include "ft_printf.h"

long long int	use_lenght_for_di(t_specifier spec, va_list ap)
{
	if (spec.length == 1)
		return (va_arg(ap, long));
	if (spec.length == 10)
		return (va_arg(ap, long long));
	if (spec.length == 2)
		return ((short int)va_arg(ap, int));
	if (spec.length == 20)
		return ((char)va_arg(ap, int));
	return (va_arg(ap, int));
}

long long int	use_lenght_for_uoxx(t_specifier spec, va_list ap)
{
	if (spec.length == 1)
		return (va_arg(ap, unsigned long int));
	if (spec.length == 10)
		return (va_arg(ap, unsigned long long int));
	if (spec.length == 2)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (spec.length == 20)
		return ((unsigned char)va_arg(ap, unsigned int));
	return (va_arg(ap, int));
}
