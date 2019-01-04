# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 16:04:14 by lmaron-g          #+#    #+#              #
#    Updated: 2018/12/27 16:04:25 by lmaron-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_D = $(addprefix ./srcs/,$(SRCS))
LIBFT_D = $(addprefix ./libft/,$(LIBFT))
OBJ_D = objs

GCCFLAGS = -Wall -Wextra -Werror

SRCS =  is_.c  \
		find.c  \
		print.c  \
		print2.c  \
		ft_itoa2.c \
		functions.c \
		ft_printf.c  \
		functions2.c  \
		sub_spec_len.c \

LIBFT = ft_itoa.c \
		ft_atoi.c  \
		ft_strcpy.c \
		ft_strdup.c  \
		ft_strlen.c   \
		ft_strnew.c    \
		ft_strdel.c     \
		ft_memcmp.c      \
		ft_memdel.c       \
		ft_memset.c        \
		ft_putstr.c         \
		ft_putnbr.c          \
		ft_putchar.c          \
		ft_strncpy.c           \
		ft_strjoin.c            \

OBJS  = $(addprefix $(OBJ_D)/,$(SRCS:.c=.o))
OBJSL = $(addprefix $(OBJ_D)/,$(LIBFT:.c=.o))

all: $(NAME)

$(NAME):
		@gcc $(GCCFLAGS) -c $(SRC_D) $(LIBFT_D) -I ./includes -I ./libft/includes
		@mkdir -p $(OBJ_D) && mv $(SRCS:.c=.o) ./$(OBJ_D) && mv $(LIBFT:.c=.o) ./$(OBJ_D)
		@ar rc $(NAME) $(OBJS) $(OBJSL)
		@ranlib $(NAME)

clean:
		@rm -rf $(OBJ_D)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
