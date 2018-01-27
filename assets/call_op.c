/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:14:32 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 18:15:57 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		call_op_swap_push(t_lst **la, t_lst **lb, char *l)
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
	return (1);
}

static	int		call_op_rotate(t_lst **la, t_lst **lb, char *l)
{
	if (!ft_strcmp(l, "ra"))
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
	return (1);
}

int				call_op(t_lst **la, t_lst **lb, char *l)
{
	call_op_swap_push(la, lb, l);
	call_op_rotate(la, lb, l);
	return (1);
}
