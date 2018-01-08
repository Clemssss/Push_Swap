/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:48:00 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/08 20:39:14 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

t_lst	*new_maillon(long long nb)
{
	t_lst	*new;

	new = NULL;
	if (!(new = (t_lst *)ft_memalloc(sizeof(t_lst))))
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

t_lst	*last_elem(t_lst *la)
{
	t_lst	*tmp;

	if (!la)
		return (NULL);
	tmp = la;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	check_sort(t_lst *la, t_lst *lb)
{
	t_lst	*tmp;

	if (lb)
		return (1);
	tmp = la;
	while (tmp && tmp->next && tmp->nb < tmp->next->nb)
		tmp = tmp->next;
	if (!tmp->next)
		return (0);
	return (1);
}
