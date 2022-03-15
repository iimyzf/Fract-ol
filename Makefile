# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 16:45:58 by yagnaou           #+#    #+#              #
#    Updated: 2022/03/09 17:05:37 by yagnaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra

SRCS = mandelbrot.c julia.c burning_ship.c main.c other_funcs.c ft_strcmp.c \
		ft_strdup.c error_and_exit.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS)
		cc $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re :	fclean all
