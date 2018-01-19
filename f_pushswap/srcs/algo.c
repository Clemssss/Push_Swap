/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:10:08 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 16:42:37 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rec_b(t_info *info, int size, int recup_b)
{
	int		count;

	info->count_b = 0;
	count = 0;
	if (size <= 3)
	{
		if (info->come)
		{
			info->come = 0;
			sort_3_2_nb_rev(&(info->lb), info, size);
		}
		else
		{
			info->come = 1;
			sort_rev_and_recup(&info->lb, info, size);
		}
		return (0);
	}
	info->mediane = fill_mediane(info->lb, size);
	push_in_a(info, &count, recup_b);
	info->come = 1;
	rec_b(info, size - count, recup_b);
	info->come = 0;
	rec_a(info, count, 1);
	recup_in_a(info, count - info->count_b);
	info->count_b = 0;
	return (0);
}

int		rec_a(t_info *info, int size, int recup_end)
{
	int		count;

	count = 0;
	info->count_a = 0;
	if (size <= 3)
	{
		if (info->come)
		{
			info->come = 0;
			sort_3_2_nb(&(info->la), info, size);
		}
		else
		{
			sort_and_recup(&info->la, info, size);
			info->come = 1;
		}
		return (0);
	}
	info->mediane = fill_mediane(info->la, size);
	push_in_b(info, &count, recup_end);
	info->come = 1;
	rec_a(info, size - count, recup_end);
	info->come = 0;
	if (!check_sort(info->la, NULL, size_lst(info->la))
			&& size_lst(info->la) + count == info->init_width)
		rec_b(info, count, 0);
	else
		rec_b(info, count, 1);
	recup_in_b(info, count - info->count_a);
	info->count_a = 0;
	return (0);
}

int				algo_push_swap(t_info *info)
{
	info->count_a = 0;
	info->count_b = 0;
	info->init_width = size_lst(info->la);
	rec_a(info, size_lst(info->la), 0);
	op_inutile(info);
	//op_fusion(info);
	if (!info->flag_v && !info->flag_c)
		print_op(info->op, 0);
	return (0);
}
