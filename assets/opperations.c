/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:14:13 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/08 16:00:48 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	op_swap(t_lst **la)
{
	long	long	stock;

	if (*la)
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

int	op_rotate(t_lst **la)
{
	t_lst	*tmp;
	t_lst	*tmp2;

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

int	op_rev_rotate(t_lst **la)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	
	if (*la)
	{
		tmp = *la;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (!tmp->next->next)
			{
				tmp2 = tmp->next;
				tmp->next = NULL;
			}
		}
		tmp2->next = (*la);
		(*la) = tmp2;
	}
	return (1);
}
