/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:08 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/10 23:04:12 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>

typedef	struct		s_lst
{
	long	long	nb;
	struct s_lst	*next;
}					t_lst;

typedef	struct		s_info
{
	int				flag_v;
}					t_info;

int					op_swap(t_lst **la);
int					op_push(t_lst **la, t_lst **lb);
int					op_rotate(t_lst **la);
int					op_rev_rotate(t_lst **la);
long	long		ft_atol_ps(const char *str);
t_lst				*create_lst(int ac, char **av);
t_lst				*new_maillon(long long nb);
t_lst				*last_elem(t_lst *la);
void				print_lst(t_lst *la);
int					check_sort(t_lst *la, t_lst *lb);
int					algo_inf_7(t_lst **a_pile, t_lst **b_pile, t_info *info);
int					algo_push_swap(t_lst **a_pile,
		t_lst **b_pile, t_info *info, t_lst *cpy);
void				aff_and_op(int (*f)(t_lst **),
				int (*f2)(t_lst **, t_lst **), char *aff,
				t_lst **la, t_lst **lb);
int					size_lst(t_lst *la);

#endif
