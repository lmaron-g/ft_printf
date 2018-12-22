#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_specifier
{
	char		flag;
	int			width;
	int 		precision;
	int 		parameter;
	int 		length;
	char 		type;
}				t_specifier;

void			ft_printf(char *src, ...);
char			*ft_ftoa(float nbr, int afterpoint);
char			*ft_itoa_base(int dec, int base, int up);
int				ft_cat_pro(char **dest, char *src);
int				ft_pow(int nb, int pow);
int				is_flag(char c);

#endif
