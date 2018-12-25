#include "ft_printf.h"
#include "libft/includes/libft.h"

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int		is_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'u'|| c == 'o' || c == 'x' \
		|| c == 'X' || c == 'f' || c == 'c'|| c == 's' || c == 'p' )
		return (1);
	return (0);
}

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char		*ft_strrev(char *str)
{
	int		i;
	int		l;
	char	t;

	l = 0;
	while (str[l] != '\0')
		l++;
	i = -1;
	while (++i < --l)
	{
		t = str[i];
		str[i] = str[l];
		str[l] = t;
	}
	return (str);
}

void		set_plus(char **src, int space, int plus)
{
	char	*new;

	if (**src != '-')
	{
		new = (char*)malloc(sizeof(char) * ft_strlen(*src) + 2);
		if (plus)
			new[0] = '+';
		else if (space)
			new[0] = ' ';
		ft_strcpy(&new[1], *src);
		ft_strdel(src);
		*src = new;
	}
}
