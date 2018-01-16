/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_inf_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:01:43 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/16 20:48:37 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				algo_inf_7(t_info *info)
{
	while (check_sort(info->la, info->lb, size_lst(info->la)))
	{
		info->last = last_elem(info->la);
		if (info->la && (info->la)->next
				&& (info->la)->nb > (info->la)->next->nb
				&& (info->la)->nb > info->last->nb)
		{
			if ((info->lb) && (info->la)->nb > (info->lb)->nb
					&& better_push(info->la, info->lb))
				opperations_list(&(info->la), &(info->lb), "pa", info);
			opperations_list(&(info->la), &(info->lb), "ra", info);
		}
		else if ((info->la) && (info->la)->next
				&& (info->la)->nb > (info->la)->next->nb
				&& (info->la)->nb < info->last->nb)
			opperations_list(&(info->la), &(info->lb), "sa", info);
		else if (check_sort(info->la, NULL, size_lst(info->la)) && (info->la)
				&& (info->la)->next && (info->la)->nb < (info->la)->next->nb
				&& (info->la)->nb < info->last->nb)
		{
			opperations_list(&(info->la), &(info->lb), "pb", info);
			if ((info->lb) && (info->lb)->next && (info->lb)->nb < (info->lb)->next->nb)
				opperations_list(&(info->la), &(info->lb), "rb", info);

		}
		else if ((info->lb) && better_push(info->la, info->lb))
			opperations_list(&(info->la), &(info->lb), "pa", info);
		else if ((info->la) && (info->la)->next && (info->la)->nb < (info->la)->next->nb
				&& (info->la)->nb > info->last->nb)
			opperations_list(&(info->la), &(info->lb), "rra", info);
		else
			opperations_list(&(info->la), &(info->lb), "ra", info);
	}
	print_op(info->op, 0);
	return (1);
}
