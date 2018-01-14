/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:08 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/14 16:14:46 by clegirar         ###   ########.fr       */
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

typedef	struct		s_lst_op
{
	char			*opp;
	struct s_lst_op	*prev;
	struct s_lst_op	*next;
}					t_lst_op;

typedef	struct		s_info
{
	t_lst			*la;
	t_lst			*lb;
	t_lst			*last;
	t_lst_op		*op;
	t_lst_op		*tail;
	int				flag_v;
	int				coup;
	int				mediane;
}					t_info;

void				remove_lst(t_lst **la);
void				remove_lst_op(t_lst_op **la);
t_lst				*cpy_lst(t_lst **la);
int					rec_a(t_info *info, int count, int recup_end);
int					rec_b(t_info *info, int count);
void				op_inutile(t_info *info);
void				push_in_b(t_info *info, int *count, int recup_end);
void				push_in_a(t_info *info, int *count);
void				recup_in_a(t_info *info, int count);
void				recup_in_b(t_info *info, int count);
void				sort_3_2_nb(t_lst **la, t_info *info, int nb_elem);
void				sort_3_2_nb_rev(t_lst **la, t_info *info, int nb_elem);
int					fill_mediane(t_lst *la, int nb_elem);
t_lst_op			*n_elem_op(t_lst_op **op, int n);
void				maillon_op_back(t_lst_op **op, t_lst_op **tail, char *l);
void				print_op(t_lst_op *op, int c);
int					opperations_list(t_lst **la, t_lst **lb, char *l,
		t_info *info);
int					check_nb_exist(t_lst *l, int nb);
int					check_nb_exist_rev(t_lst *l, int nb);
int					better_push(t_lst *la, t_lst *lb);
int					op_swap(t_lst **la, t_lst **lb);
int					op_push(t_lst **la, t_lst **lb);
int					op_rotate(t_lst **la, t_lst **lb);
int					op_rev_rotate(t_lst **la, t_lst **lb);
long	long		ft_atol_ps(const char *str);
t_lst				*create_lst(int ac, char **av);
t_lst				*new_maillon(long long nb);
t_lst_op			*new_maillon_op(char *str);
t_lst				*last_elem(t_lst *la);
void				print_lst(t_lst *la);
void				print_piles(t_lst *la, t_lst *lb);
int					check_sort_rev(t_lst *la, t_lst *lb, int nb_elem);
int					check_sort(t_lst *la, t_lst *lb, int nb_elem);
int					algo_inf_7(t_info *info);
int					algo_push_swap(t_info *info);
void				aff_and_op(int (*f)(t_lst **),
				int (*f2)(t_lst **, t_lst **), char *aff,
				t_lst **la, t_lst **lb);
int					size_lst(t_lst *la);

#endif
