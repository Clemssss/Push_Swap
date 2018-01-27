/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_list2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:05:17 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 18:06:56 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*sort_lst(t_lst *lst)
{
	int		overflow;
	t_lst	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (lst->nb > lst->next->nb)
		{
			overflow = lst->nb;
			lst->nb = lst->next->nb;
			lst->next->nb = overflow;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int		neme_elem(t_lst *lst, int nb)
{
	int		i;
	t_lst	*tmp;

	tmp = lst;
	i = 0;
	while (tmp && tmp->nb != nb)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
