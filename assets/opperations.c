/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:14:13 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 18:16:39 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	opperations_list(t_lst **la, t_lst **lb, char *l, t_info *info)
{
	call_op(la, lb, l);
	maillon_op_back(&(info->op), &(info->tail), l);
	return (1);
}

int	op_swap(t_lst **la, t_lst **lb)
{
	long	long	stock;

	(void)lb;
	if (*la && (*la)->next)
	{
		stock = (*la)->next->nb;
		(*la)->next->nb = (*la)->nb;
		(*la)->nb = stock;
	}
	return (1);
}

int	op_push(t_lst **l1, t_lst **l2)
{
	t_lst	*tmp;

	if (*l1)
	{
		tmp = (*l2);
		(*l2) = (*l1);
		(*l1) = (*l1)->next;
		(*l2)->next = tmp;
	}
	return (1);
}

int	op_rotate(t_lst **la, t_lst **lb)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	(void)lb;
	if (*la)
	{
		tmp = last_elem(*la);
		tmp2 = (*la);
		tmp->next = tmp2;
		(*la) = (*la)->next;
		tmp2->next = NULL;
	}
	return (1);
}

int	op_rev_rotate(t_lst **la, t_lst **lb)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	(void)lb;
	if (*la && (*la)->next)
	{
		tmp = *la;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = (*la);
		(*la) = tmp2;
	}
	return (1);
}
