# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 11:30:22 by clegirar          #+#    #+#              #
#    Updated: 2017/12/06 18:46:17 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_libmlx.a

SRCS	=	./srcs/clear_pixels.c			\
				./srcs/draw_pixel.c				\
				./srcs/draw_line.c				\
				./srcs/convert_hsv_rgb.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I./includes/

all			:	$(NAME)

$(NAME)	:	$(OBJS)
					ar rc $(NAME) $(OBJS)
					ranlib $(NAME)

%.o		: 	%.c
					$(CC) -o $@ -c $< $(CFLAGS)

clean	:
				rm -rf $(OBJS)

fclean	:
					rm -rf $(OBJS)
					rm -rf $(NAME)

re			:	fclean all

.PHONY	:	all clean fclean re
