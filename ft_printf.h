#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_flag
{
	char		flag;
	int			width;
	int 		precision;
	int 		parameter;
	int 		length;
	char 		type;
}				t_flag;

void			ft_printf(char *src, ...);

#endif
