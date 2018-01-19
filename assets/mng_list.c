/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:48:00 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 18:07:05 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		size_lst(t_lst *la)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	if (!la)
		return (0);
	tmp = la;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		higher_elem(t_lst *la)
{
	int		stock;
	t_lst	*tmp;

	tmp = la;
	stock = tmp->nb;
	while (tmp)
	{
		if (tmp->nb > stock)
			stock = tmp->nb;
		tmp = tmp->next;
	}
	return (stock);
}

void	remove_lst(t_lst **la)
{
	if (!(*la))
		return ;
	while (*la)
	{
		free(*la);
		(*la) = (*la)->next;
	}
	*la = NULL;
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
