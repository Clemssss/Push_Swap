# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 14:46:55 by clegirar          #+#    #+#              #
#    Updated: 2018/01/19 19:01:11 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../visu

SRCS	=	./srcs/main.c						\
			./srcs/visu.c						\
			./srcs/do_change.c					\
			./srcs/print_visu.c					\
			../assets/ft_atol_ps.c				\
			../assets/create_list.c				\
			../assets/opperations.c				\
			../assets/call_op.c					\
			../assets/mng_list.c				\
			../assets/mng_list2.c				\
			../assets/mediane.c					\
			../assets/mng_list_op.c				\
			../assets/check.c					\
			../assets/print.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I../libft/ -I../includes -I./minilibx_macos -I./lib_mlx/includes

LIB_PATH	=	../lib_mlx/ft_libmlx.a -L ../libft/ -lft -lmlx -framework OpenGL -framework AppKit -framework Opencl -lm

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C ../lib_mlx
	make -C ../minilibx_macos
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB_PATH)

clean	:
	make clean -C ../lib_mlx
	make clean -C ../minilibx_macos
	$(RM) $(OBJS)

fclean	:	clean
	make fclean -C ../lib_mlx
	make clean -C ../minilibx_macos
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
