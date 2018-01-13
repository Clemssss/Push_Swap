# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 14:46:55 by clegirar          #+#    #+#              #
#    Updated: 2018/01/13 14:14:42 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../push_swap

SRCS	=	./srcs/main.c				\
			./srcs/algo_inf_7.c			\
			./srcs/algo.c				\
			./srcs/push_in_piles.c		\
			./srcs/recup_in_piles.c		\
			./srcs/sort_3_2_nb.c		\
			./srcs/opti_op.c			\
			../assets/opperations.c		\
			../assets/create_list.c		\
			../assets/mng_list.c		\
			../assets/ft_atol_ps.c		\
			../assets/check.c			\
			../assets/mng_list_op.c		\
			../assets/mediane.c			\
			../assets/print.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I ../includes

LIB_PATH	=	-L ../libft/ -lft

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB_PATH)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
