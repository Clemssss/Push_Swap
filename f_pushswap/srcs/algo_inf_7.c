/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_inf_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:01:43 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 18:29:59 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		better_push(t_lst *a_pile, t_lst *b_pile)
{
	t_lst	*tmp;

	if (a_pile->next)
		tmp = a_pile->next;
	if (a_pile && a_pile->nb == b_pile->nb + 1)
		return (1);
	while (tmp)
	{
		if (tmp->nb < a_pile->nb && tmp->nb > b_pile->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static	void	rest_conditions(t_info *info)
{
	if (check_sort(info->la, NULL, size_lst(info->la)) && (info->la)
			&& (info->la)->next && (info->la)->nb < (info->la)->next->nb
			&& (info->la)->nb < info->last->nb)
	{
		opperations_list(&(info->la), &(info->lb), "pb", info);
		if ((info->lb) && (info->lb)->next
				&& (info->lb)->nb < (info->lb)->next->nb)
			opperations_list(&(info->la), &(info->lb), "rb", info);
	}
	else if ((info->lb) && better_push(info->la, info->lb))
		opperations_list(&(info->la), &(info->lb), "pa", info);
	else if ((info->la) && (info->la)->next
			&& (info->la)->nb < (info->la)->next->nb
			&& (info->la)->nb > info->last->nb)
		opperations_list(&(info->la), &(info->lb), "rra", info);
	else
		opperations_list(&(info->la), &(info->lb), "ra", info);
}

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
		else
			rest_conditions(info);
	}
	print_op(info->op, 0);
	return (1);
}
