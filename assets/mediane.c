/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:06:56 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/16 23:09:49 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap(int *tab, int a, int b)
{
	int tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

static	void	quick_sort(int *tab, int start, int end)
{
	int left;
	int right;
	int pivot;

	left = start;
	right = end;
	if (start >= end)
		return ;
	pivot = tab[start];
	while (1)
	{
		while (tab[right] > pivot)
			right--;
		while (tab[left] < pivot)
			left++;
		if (left < right)
			swap(tab, left, right);
		else
			break ;
	}
	quick_sort(tab, start, right);
	quick_sort(tab, right + 1, end);
}

int				fill_mediane(t_lst *la, int size, int c, int nb)
{
	int		tab[size];
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = la;
	while (i < size && tmp)
	{
		tab[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	quick_sort(tab, 0, size - 1);
	if (!c)
		return (tab[i / 2]);
	i = 0;
	while (i < size && tab[i] != nb)
		i++;
	return (i);
}
