/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:14:13 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/12 20:26:23 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		opperations_list(t_lst **la, t_lst **lb, char *l, t_info *info)
{
	if (!ft_strcmp(l, "sa"))
		op_swap(la, NULL);
	else if (!ft_strcmp(l, "sb"))
		op_swap(lb, NULL);
	else if (!ft_strcmp(l, "ss"))
	{
		op_swap(la, NULL);
		op_swap(lb, NULL);
	}
	else if (!ft_strcmp(l, "pa"))
		op_push(lb, la);
	else if (!ft_strcmp(l, "pb"))
		op_push(la, lb);
	else if (!ft_strcmp(l, "ra"))
		op_rotate(la, NULL);
	else if (!ft_strcmp(l, "rb"))
		op_rotate(lb, NULL);
	else if (!ft_strcmp(l, "rr"))
	{
		op_rotate(la, NULL);
		op_rotate(lb, NULL);
	}
	else if (!ft_strcmp(l, "rra"))
		op_rev_rotate(la, NULL);
	else if (!ft_strcmp(l, "rrb"))
		op_rev_rotate(lb, NULL);
	else if (!ft_strcmp(l, "rrr"))
	{
		op_rev_rotate(la, NULL);
		op_rev_rotate(lb, NULL);
	}
	maillon_op_back(&(info->op), &(info->tail), l);
	info->coup += 1;
	if (info->flag_v)
	{
		ft_dprintf(1, "%s\n", n_elem_op(&(info->op), info->coup - 1)->opp);
		ft_dprintf(1, "\nl1 : ");
		print_lst(*la);
		ft_dprintf(1, "\nl2 : ");
		print_lst(*lb);
		ft_dprintf(1, "\nCOUP = %d\n\n", info->coup);
	}
	return (1);
}

int	op_swap(t_lst **la, t_lst **lb)
{
	long	long	stock;

	(void)lb;
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
