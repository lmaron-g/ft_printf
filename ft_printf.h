#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

typedef struct		s_specifier
{
	int 			precision;
	int 			parameter;
	int				flag_m;
	int				flag_p;
	int				flag_s;
	int				flag_h;
	int				flag_z;
	int 			length;
	int				width;
	char 			type;
}					t_specifier;

void				ft_printf(char *src, ...);
char				*ft_ftoa(float nbr, int afterpoint);
char				*ft_itoa_ll(long long int nb);
char				*ft_itoa_ull(unsigned long long nb);
char				*ft_itoa_base(int dec, int base, int up);
char				*ft_itoa_base_ull(unsigned long long dec, int base, char x);
int					ft_cat_pro(char **dest, char *src);
unsigned long long	ft_pow(int nb, int pow);
char				*ft_strrev(char *str);
void				set_plus(char **src, int space, int plus);
void				set_pref(char **src, char type);
int					is_flag(char c);
int					is_type(char c);
void				add_zero(char **src, int precision);
void				add_zero_h(char **src, int precision, int h, int z);
void				find_flags(t_specifier *spec, char *src);
int 				find_width(char *src, va_list ap);
int					find_lenght(char *src);
int					find_precision(char *src, va_list ap);
long long int		use_lenght_for_di(t_specifier spec, va_list ap);
long long int		use_lenght_for_uoxx(t_specifier spec, va_list ap);
void				print_specifier_di(t_specifier spec, long long int nbr);
void				print_specifier_u(t_specifier spec, unsigned long long nbr);
void				print_specifier_x(t_specifier spec, unsigned long long nbr);
void				print_specifier_s(t_specifier spec, va_list ap);
void				print_specifier_c(t_specifier spec, va_list ap);
void				print_specifier_p(t_specifier spec, va_list ap);

#endif
