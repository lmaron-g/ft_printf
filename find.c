#include "libft/includes/libft.h"
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

char 		find_flag(char *src)
{
	if (is_flag(*src))
		return (*src);
	return (0);
}

int 		find_width(char *src, va_list ap)
{
	int		i;
	int		out;

	i = 0;
	if (is_flag(src[i]))
		i++;
	if (src[i] == '*')
		return (va_arg(ap, int));
	if (ft_atoi(&src[i]))
		return (ft_atoi(&src[i]));
	return (0);
}

int			find_precision(char *src, va_list ap)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != '.' && !ft_isalpha(src[i]))
		i++;
	if (src[i++] == '.')
	{
		if (src[i] == '*')
			return (va_arg(ap, int));
		if (ft_atoi(&src[i]))
			return (ft_atoi(&src[i]));
	}
	return (0);
}

int			contains_lenght(const char *src, const char *sub)
{
	size_t	n;

	n = ft_strlen((char*)sub);
	while (*src && !is_type(*src))
		if (!ft_memcmp(src++, sub, n))
			return (1);
	return (0);
}

int			find_lenght(char *src)
{
	if (contains_lenght(src, "hh"))
		return (20);
	if (contains_lenght(src, "ll"))
		return (10);
	if (contains_lenght(src, "L"))
		return (3);
	if (contains_lenght(src, "h"))
		return (2);
	if (contains_lenght(src, "l"))
		return (1);
	return (0);
}
