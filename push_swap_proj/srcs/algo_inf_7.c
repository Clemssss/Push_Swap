/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_inf_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:01:43 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/12 12:04:15 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		push_in_a(t_info *info)
{
	if (info->la && info->la->next && info->la->nb > info->la->next->nb
			&& info->la->nb > info->last->nb)
	{
		if (info->la && info->lb && info->la->nb > info->lb->nb
				&& better_push(info->la, info->lb))
			opperations_list(&(info->la), &(info->lb), "pa", info);
		if (info->lb && info->lb->next && info->lb->nb < info->lb->next->nb)
			opperations_list(&(info->la), &(info->lb), "rr", info);
		else
			opperations_list(&(info->la), &(info->lb), "ra", info);
		return (1);
	}
	else if (info->la && info->la->next && info->la->nb > info->la->next->nb
			&& info->la->nb < info->last->nb)
	{
		opperations_list(&(info->la), &(info->lb), "sa", info);
		return (1);
	}
	return (0);
}

static	int		push_in_b(t_info *info)
{
	if (check_sort(info->la, NULL, size_lst(info->la))
			&& info->la->nb < info->la->next->nb && info->la->nb < info->last->nb)
	{
		opperations_list(&(info->la), &(info->lb), "pb", info);
		if (info->lb && info->lb->next && info->lb->nb < info->lb->next->nb)
			opperations_list(&(info->la), &(info->lb), "rb", info);
	}
	else if (better_push(info->la, info->lb))
		opperations_list(&(info->la), &(info->lb), "pa", info);
	else
		opperations_list(&(info->la), &(info->lb), "ra", info);
	return (1);
}

int				algo_inf_7(t_info *info)
{
	while (check_sort(info->la, info->lb, size_lst(info->la)))
	{
		info->last = last_elem(info->la);
		if (!push_in_a(info))
			push_in_b(info);
	}
	print_piles(info->la, info->lb);
	return (1);
}
