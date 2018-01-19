/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:10:12 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 14:28:49 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(t_lst_op *op, int c)
{
	t_lst_op	*tmp;
	int			i;

	tmp = op;
	i = 0;
	while (tmp)
	{
		if (c == 1)
			ft_dprintf(1, "%d : %s\n", ++i, tmp->opp);
		else if (c == 0)
			ft_dprintf(1, "%s\n", tmp->opp);
		tmp = tmp->next;
	}
}

void	print_lst(t_lst *la)
{
	t_lst	*tmp;

	tmp = la;
	while (tmp)
	{
		ft_dprintf(1, "%lld ", tmp->nb);
		tmp = tmp->next;
	}
}

void	print_piles(t_lst *la, t_lst *lb)
{
	ft_dprintf(1, "\nl1 : ");
	print_lst(la);
	ft_dprintf(1, "\nl2 : ");
	print_lst(lb);
	ft_dprintf(1, "\n\n");
}
