/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:08 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 17:55:16 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../lib_mlx/includes/libmlx.h"
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
	t_pict			*pict;
	t_window		*win;
	t_pos_iso		*iso;
	t_hsv			*hsv;
	t_lst			*la;
	t_lst			*lb;
	t_lst			*last;
	t_lst			*ordre;
	t_lst_op		*tmp;
	t_lst_op		*op;
	t_lst_op		*tail;
	char			**tab;
	int				flag_v;
	int				flag_c;
	int				coup;
	int				mediane;
	int				space;
	int				init_width;
	int				init_height;
	int				key[269];
	float			pas_h;
	int				come;
	int				count_a;
	int				count_b;
}					t_info;

void				sort_and_recup(t_lst **la, t_info *info, int size);
void				sort_rev_and_recup(t_lst **la, t_info *info, int size);
t_lst				*sort_lst(t_lst *lst);
void				free_struct_visu(t_info *info);
int					visu(t_info *info);
int					check_string_av(char *av);
int					do_change(t_info *info);
int					neme_elem(t_lst *la, int nb);
int					higher_elem(t_lst *la);
int					call_op(t_lst **la, t_lst **lb, char *l);
void				free_struct(t_info *info);
void				remove_lst(t_lst **la);
void				remove_lst_op(t_lst_op **la);
t_lst				*cpy_lst(t_lst **la);
int					rec_a(t_info *info, int count, int recup_end);
int					rec_b(t_info *info, int count, int recup_b);
void				op_inutile(t_info *info);
void				push_in_b(t_info *info, int *count, int recup_end);
void				push_in_a(t_info *info, int *count, int recup_b);
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
t_lst				*create_lst(char **av);
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
