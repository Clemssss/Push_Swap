# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 14:46:55 by clegirar          #+#    #+#              #
#    Updated: 2018/01/13 14:16:10 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../checker

SRCS	=	./srcs/main.c						\
			../assets/ft_atol_ps.c				\
			../assets/create_list.c				\
			../assets/opperations.c				\
			../assets/mng_list.c				\
			../assets/mng_list_op.c				\
			../assets/check.c					\
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
