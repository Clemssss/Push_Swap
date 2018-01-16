/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:10:08 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/16 22:46:37 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rec_b(t_info *info, int size)
{
	int		count;

	count = 0;
	if (size <= 3)
	{
		sort_3_2_nb_rev(&(info->lb), info, size);
		return (0);
	}
	info->mediane = fill_mediane(info->lb, size, 0, 0);
	push_in_a(info, &count);
	rec_b(info, size - count);
	rec_a(info, count, 1);
	recup_in_a(info, count);
	return (0);
}

int		rec_a(t_info *info, int size, int recup_end)
{
	int		count;

	count = 0;
	if (size <= 3)
	{
		sort_3_2_nb(&(info->la), info, size);
		return (0);
	}
	info->mediane = fill_mediane(info->la, size, 0, 0);
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
	if (!info->flag_v && !info->flag_n)
		print_op(info->op, 0);
	return (0);
}
