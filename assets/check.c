/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:02:49 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/15 18:23:53 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_string_av(char *av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		check_nb_exist(t_lst *l, int nb)
{
	t_lst	*tmp;

	if (!l)
		return (0);
	tmp = l;
	while (tmp)
	{
		if (tmp->nb <= nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		check_nb_exist_rev(t_lst *l, int nb)
{
	t_lst	*tmp;

	if (!l)
		return (0);
	tmp = l;
	while (tmp)
	{
		if (tmp->nb > nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		better_push(t_lst *a_pile, t_lst *b_pile)
{
	t_lst	*tmp;

	if (a_pile->next)
		tmp = a_pile->next;
	if (a_pile && a_pile->nb == b_pile->nb + 1)
		return (1);
	while (tmp)
	{
		if (tmp->nb < a_pile->nb && tmp->nb > b_pile->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		check_sort(t_lst *la, t_lst *lb, int nb_elem)
{
	t_lst	*tmp;
	int		i;

	if (lb)
		return (1);
	tmp = la;
	i = 1;
	while (tmp && tmp->next && tmp->nb < tmp->next->nb && i < nb_elem)
	{
		tmp = tmp->next;
		i++;
	}
	if (!tmp->next || i == nb_elem)
		return (0);
	return (1);
}

int		check_sort_rev(t_lst *la, t_lst *lb, int nb_elem)
{
	t_lst	*tmp;
	int		i;

	if (lb)
		return (1);
	tmp = la;
	i = 1;
	while (tmp && tmp->next && tmp->nb > tmp->next->nb && i < nb_elem)
	{
		tmp = tmp->next;
		i++;
	}
	if (!tmp->next || i == nb_elem)
		return (0);
	return (1);
}
