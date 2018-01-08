/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:53:19 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/08 20:39:12 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		better_push(t_lst *a_pile, t_lst *b_pile)
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

static	void	aff_and_op(int (*f)(t_lst **),
		int (*f2)(t_lst **, t_lst **), char *aff, t_lst **la, t_lst **lb)
{
	if (f)
		f(la);
	else if (f2)
		f2(la, lb);
	if (aff)
		ft_dprintf(1, "%s\n\n", aff);
}

static	int		algo_push_swap(t_lst **la, t_lst **lb, t_info *info)
{
	t_lst	*last;
	int		i;

	i = 0;
	while (check_sort(*la, *lb))
	{
		last = last_elem(*la);
		if ((*la) && (*la)->next
				&& (*la)->nb > (*la)->next->nb && (*la)->nb > last->nb)
		{
			if ((*la) && (*lb) && (*la)->nb > (*lb)->nb
					&& better_push(*la, *lb))
				aff_and_op(NULL, &op_push, "pa", lb , la);
			if ((*lb) && (*lb)->next && (*lb)->nb < (*lb)->next->nb)
			{
				aff_and_op(&op_rotate, NULL, NULL, la, NULL);
				aff_and_op(&op_rotate, NULL, "rr", lb, NULL);
			}
			else
				aff_and_op(&op_rotate, NULL, "ra", la, NULL);
		}
		else if ((*la) && (*la)->next
				&& (*la)->nb > (*la)->next->nb && (*la)->nb < last->nb)
			aff_and_op(&op_swap, NULL, "sa", la, NULL);
		else if (check_sort(*la, NULL)
				&& (*la)->nb < (*la)->next->nb && (*la)->nb < last->nb)
		{
			aff_and_op(NULL, &op_push, "pb", la, lb);
			if ((*lb) && (*lb)->next && (*lb)->nb < (*lb)->next->nb)
				aff_and_op(&op_rotate, NULL, "rb", lb, NULL);
		}
		else if (better_push(*la, *lb))
			aff_and_op(NULL, &op_push, "pa", lb, la);
		else
			aff_and_op(&op_rotate, NULL, "ra", la, NULL);
		if (info->flag_v)
		{
			ft_dprintf(1, "l1 : ");
			print_lst(*la);
			ft_dprintf(1, "\nl2 : ");
			print_lst(*lb);
			ft_dprintf(1, "\n");
			i++;
			ft_dprintf(1, "COUP = %d\n\n", i);
		}
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_lst			*la;
	t_lst			*lb;
	t_info			info;

	if (ac == 1)
	{
		ft_dprintf(1, "./push_swap [-v] number 0 number 1 ... number n\n");
		return (0);
	}
	info.flag_v = 0;
	if (!ft_strcmp(av[1], "-v"))
		info.flag_v = 1;
	la = create_lst(ac, av);
	lb = NULL;
	if (info.flag_v)
	{
		ft_dprintf(1, "l1 : ");
		print_lst(la);
		ft_dprintf(1, "\nl2 : \n\n");
		print_lst(lb);
	}
	if (!algo_push_swap(&la, &lb, &info))
		return (-1);
	return (0);
}
