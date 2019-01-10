/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:02:10 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/27 17:45:22 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct		s_specifier
{
	int				precision;
	int				flag_minus;
	int				flag_plus;
	int				flag_spase;
	int				flag_hash;
	int				flag_zero;
	int				length;
	int				width;
	char			type;
}					t_specifier;

int					ft_printf(char *src, ...);
char				*ft_ftoa(long double nbr, int afterpoint);
char				*ft_itoa_ll(long long int nb);
char				*ft_itoa_ull(unsigned long long nb);
char				*ft_itoa_base(int dec, int base, int up);
char				*ft_itoa_base_ull(unsigned long long dec, int base, char x);
int					ft_cat_pro(char **dest, char *src);
int					ft_nbrlen(long long int nb);
int					ft_nbrlen_u(unsigned long long nb);
unsigned long long	ft_pow(int nb, int pow);
char				*ft_strrev(char *str);
char				*round_it(char **src);
void				set_plus(char **src, t_specifier spec);
void				set_pref(char **src, char type);
int					is_flag(char c);
int					is_type(char c);
int					is_right(char c);
void				prec_zero(char **src, int precision);
void				add_zero(char **src, t_specifier spec);
void				find_flags(t_specifier *spec, char *src);
int					find_width(char *src, va_list ap);
int					find_lenght(char *src);
int					find_precision(char *src, va_list ap);
long double			use_lenght_for_f(t_specifier spec, va_list ap);
long long int		use_lenght_for_di(t_specifier spec, va_list ap);
long long int		use_lenght_for_uoxx(t_specifier spec, va_list ap);
void				print_specifier_di(t_specifier spec, long long int nbr);
void				print_specifier_u(t_specifier spec, unsigned long long nbr);
void				print_specifier_x(t_specifier spec, unsigned long long nbr);
void				print_specifier_b(t_specifier spec, unsigned long long nbr);
void				print_specifier_o(t_specifier spec, unsigned long long nbr);
void				print_specifier_f(t_specifier spec, long double nbr);
void				print_specifier_S(t_specifier spec, va_list ap);
void				print_specifier_s(t_specifier spec, va_list ap);
void				print_specifier_C(t_specifier spec, va_list ap);
void				print_specifier_c(t_specifier spec, va_list ap);
void				print_specifier_p(t_specifier spec, va_list ap);

#endif
