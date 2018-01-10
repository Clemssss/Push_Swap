# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 14:21:04 by clegirar          #+#    #+#              #
#    Updated: 2018/01/10 23:04:13 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	compile

all		:	$(NAME)

$(NAME)	:
	make -C libft
	make -C checker_push_swap
	make -C push_swap_proj

clean	:
	make clean -C libft
	make clean -C checker_push_swap
	make clean -C push_swap_proj

fclean	:
	make fclean -C libft
	make fclean -C checker_push_swap
	make fclean -C push_swap_proj

re		:	fclean all

.PHONY	:	all clean fclean re
