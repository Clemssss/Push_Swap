/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:10:08 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/10 23:04:08 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		fill_mediane(t_lst *la)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	int		i;
	int		len;

	tmp = la;
	while (tmp)
	{
		tmp2 = la;
		while (tmp2)
		{
			if (tmp2->next && tmp2->nb > tmp2->next->nb)
				op_swap(&tmp2);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	tmp = la;
	i = 0;
	len = size_lst(la) / 2 - 1;
	while (i < len)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->nb);
}

int				algo_push_swap(t_lst **la, t_lst **lb, t_info *info, t_lst *cpy)
{
	int		mediane;

	mediane = fill_mediane(*la);
	*la = cpy;
	(void)lb;
	(void)info;
	return (0);
}
