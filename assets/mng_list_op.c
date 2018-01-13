/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_list_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:05:42 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/13 14:44:22 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst_op	*n_elem_op(t_lst_op **op, int n)
{
	int			i;
	t_lst_op	*tmp;

	i = 0;
	tmp = *op;
	while (i < n)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void		maillon_op_back(t_lst_op **op, t_lst_op **tail, char *l)
{
	t_lst_op	*tmp;

	tmp = NULL;
	if (!(tmp = (t_lst_op*)ft_memalloc(sizeof(t_lst_op))))
		return ;
	tmp->opp = ft_strdup(l);
	tmp->next = NULL;
	if (!(*tail))
	{
		tmp->prev = NULL;
		*op = tmp;
		*tail = tmp;
	}
	else
	{
		(*tail)->next = tmp;
		tmp->prev = *tail;
		*tail = tmp;
	}
}
