# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 14:21:04 by clegirar          #+#    #+#              #
#    Updated: 2018/01/16 16:28:56 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	compile

all		:	$(NAME)

$(NAME)	:
	make -C libft
	make -C f_checker
	make -C f_pushswap
	make -C f_visu

clean	:
	make clean -C libft
	make clean -C f_checker
	make clean -C f_pushswap
	make clean -C f_visu

fclean	:
	make fclean -C libft
	make fclean -C f_checker
	make fclean -C f_pushswap
	make fclean -C f_visu

re		:	fclean all

.PHONY	:	all clean fclean re
