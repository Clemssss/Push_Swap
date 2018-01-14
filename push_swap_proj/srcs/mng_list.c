/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:48:00 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/14 16:14:39 by clegirar         ###   ########.fr       */
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

t_lst	*maillon_back(t_lst **tmp, long long nb)
{
	t_lst	*tmp2;

	tmp2 = new_maillon(nb);
	if (*tmp)
		(*tmp)->next = tmp2;
	return (tmp2);
}

t_lst	*cpy_lst(t_lst **la)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	t_lst	*new;

	if (!(*la))
		return (NULL);
	tmp = *la;
	new = NULL;
	tmp2 = NULL;
	while (tmp)
	{
		tmp2 = maillon_back(&tmp2, tmp->nb);
		if (new == NULL)
			new = tmp2;
		tmp = tmp->next;
	}
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
