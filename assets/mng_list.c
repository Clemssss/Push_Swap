/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:48:00 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/12 18:02:57 by clegirar         ###   ########.fr       */
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

static void		swap(int *tab, int a, int b)
{
	int tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

void			quick_sort(int *tab, int start, int end)
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

int		fill_mediane(t_lst *la, int size)
{
	int tab[size];
	int i;
	t_lst	*tmp;

	i = 0;
	tmp = la;
	while (i < size)
	{
		tab[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	quick_sort(tab, 0, size - 1);
	return (tab[i / 2]);
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
	ft_dprintf(1, "\n");
}

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

t_lst	*n_elem(t_lst **op, int n)
{
	int			i;
	t_lst	*tmp;

	i = 0;
	tmp = *op;
	while (i < n)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void	maillon_op_back(t_lst_op **op, t_lst_op **tail, char *l)
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

int	check_sort(t_lst *la, t_lst *lb, int nb_elem)
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

int	check_sort_rev(t_lst *la, t_lst *lb, int nb_elem)
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
