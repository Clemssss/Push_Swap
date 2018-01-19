# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 14:46:55 by clegirar          #+#    #+#              #
#    Updated: 2018/01/19 18:51:18 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../push_swap

SRCS	=	./srcs/main.c				\
			./srcs/algo_inf_7.c			\
			./srcs/algo.c				\
			./srcs/push_in_piles.c		\
			./srcs/recup_in_piles.c		\
			./srcs/sort_3_2_nb.c		\
			./srcs/sort_and_recup.c		\
			./srcs/sort_rev_and_recup.c	\
			./srcs/opti_op.c			\
			../assets/opperations.c		\
			../assets/call_op.c			\
			../assets/create_list.c		\
			../assets/mng_list.c		\
			../assets/mng_list2.c		\
			../assets/ft_atol_ps.c		\
			../assets/check.c			\
			../assets/mng_list_op.c		\
			../assets/mediane.c			\
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
	$(CC) $(OBJS) $(LIB_PATH) -o $(NAME)

clean	:
	make clean -C ../lib_mlx
	make clean -C ../minilibx_macos
	$(RM) $(OBJS)

fclean	:
	make fclean -C ../lib_mlx
	make clean -C ../minilibx_macos
	$(RM) $(OBJS)
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
