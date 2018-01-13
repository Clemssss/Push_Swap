/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:10:08 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/13 14:05:34 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rec_b(t_info *info, int size)
{
	t_lst	*cpy;
	int		count;

	count = 0;
	if (size <= 3)
	{
		sort_3_2_nb_rev(&(info->lb), info, size);
		return (0);
	}
	cpy = cpy_lst(&(info->lb));
	info->mediane = fill_mediane(cpy, size);
	push_in_a(info, &count);
	rec_b(info, size - count);
	rec_a(info, count, 1);
	recup_in_a(info, count);
	return (0);
}

int		rec_a(t_info *info, int size, int recup_end)
{
	int		count;
	t_lst	*cpy;

	count = 0;
	if (size <= 3)
	{
		sort_3_2_nb(&(info->la), info, size);
		return (0);
	}
	cpy = cpy_lst(&(info->la));
	info->mediane = fill_mediane(cpy, size);
	push_in_b(info, &count, recup_end);
	rec_a(info, size - count, recup_end);
	rec_b(info, count);
	recup_in_b(info, count);
	return (0);
}

int				algo_push_swap(t_info *info)
{
	rec_a(info, size_lst(info->la), 0);
	op_inutile(info);
	//op_fusion(info);
	if (!info->flag_v)
		print_op(info->op, 0);
	//print_piles(info->la, info->lb);
	return (0);
}
