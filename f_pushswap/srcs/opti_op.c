/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:53:31 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 18:42:18 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	join_pointers(t_lst_op **tmp, t_lst_op **after,
		t_lst_op **before, t_lst_op **stock)
{
	if ((*tmp)->prev && (*tmp)->next->next)
	{
		*after = (*tmp)->next->next;
		*before = (*tmp)->prev;
		(*before)->next = *after;
		(*after)->prev = *before;
		*stock = *before;
	}
	else if ((*tmp)->prev && !(*tmp)->next->next)
	{
		*after = NULL;
		*before = (*tmp)->prev;
		(*before)->next = *after;
		(*after)->prev = *before;
		*stock = *before;
	}
	else if (!(*tmp)->prev && (*tmp)->next->next)
	{
		*after = (*tmp)->next->next;
		*before = NULL;
		(*before)->next = *after;
		(*after)->prev = *before;
		*stock = *after;
	}
}

static	void	del_maillon(t_lst_op **tmp)
{
	t_lst_op	*after;
	t_lst_op	*before;
	t_lst_op	*stock;

	after = NULL;
	before = NULL;
	stock = NULL;
	join_pointers(tmp, &after, &before, &stock);
	ft_strdel(&(*tmp)->next->opp);
	ft_strdel(&(*tmp)->opp);
	free((*tmp)->next);
	free((*tmp));
	*tmp = NULL;
	*tmp = stock;
}

static	int		check_del_maillon(t_lst_op **tmp, char *a, char *b)
{
	if ((ft_strcmp((*tmp)->opp, a) == 0
				&& ft_strcmp((*tmp)->next->opp, b) == 0)
			|| (ft_strcmp((*tmp)->opp, b) == 0
				&& ft_strcmp((*tmp)->next->opp, a) == 0))
	{
		del_maillon(tmp);
		return (1);
	}
	return (0);
}

void			op_inutile(t_info *info)
{
	t_lst_op	*tmp;

	tmp = info->op;
	while (tmp)
	{
		if (tmp->next)
		{
			while (check_del_maillon(&tmp, "pa", "pb"))
			{
			}
			while (check_del_maillon(&tmp, "rra", "ra"))
			{
			}
			while (check_del_maillon(&tmp, "rrb", "rb"))
			{
			}
		}
		tmp = tmp->next;
	}
}
