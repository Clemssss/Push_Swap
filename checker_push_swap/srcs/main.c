/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:52:05 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/08 15:50:50 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	opperations_list(t_lst **la, t_lst **lb, char *l)
{
	if (!ft_strcmp(l, "sa"))
		return (op_swap(la));
	else if (!ft_strcmp(l, "sb"))
		return (op_swap(lb));
	else if (!ft_strcmp(l, "ss"))
	{
		op_swap(la);
		return (op_swap(lb));
	}
	else if (!ft_strcmp(l, "pa"))
		return (op_push(lb, la));
	else if (!ft_strcmp(l, "pb"))
		return (op_push(la, lb));
	else if (!ft_strcmp(l, "ra"))
		return (op_rotate(la));
	else if (!ft_strcmp(l, "rb"))
		return (op_rotate(lb));
	else if (!ft_strcmp(l, "rr"))
	{
		op_rotate(la);
		return (op_rotate(lb));
	}
	else if (!ft_strcmp(l, "rra"))
		return (op_rev_rotate(la));
	else if (!ft_strcmp(l, "rrb"))
		return (op_rev_rotate(lb));
	else if (!ft_strcmp(l, "rrr"))
	{
		op_rev_rotate(la);
		return (op_rev_rotate(lb));
	}
	return (1);
}

static	int	check_sort(t_lst **la, t_lst **lb)
{
	t_lst	*tmp;

	if (*lb)
		return (1);
	tmp = *la;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->nb > tmp->next->nb)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static	int	algo_checker(t_lst *la, t_lst *lb, t_info *info)
{
	char	*l;
	int		ret;

	while ((ret = get_next_line(0, &l)))
	{
		if (ft_strcmp(l, "sa") && ft_strcmp(l, "sb") && ft_strcmp(l, "ss")
				&& ft_strcmp(l, "pa") && ft_strcmp(l, "pb")
				&& ft_strcmp(l, "ra") && ft_strcmp(l, "rb")
				&& ft_strcmp(l, "rr") && ft_strcmp(l, "rra")
				&& ft_strcmp(l, "rrb") && ft_strcmp(l, "rrr"))
		{
			ft_dprintf(2, "Error\n");
			ft_strdel(&l);
			exit(EXIT_FAILURE);
		}
		else
		{
			opperations_list(&la, &lb, l);
			if (info->flag_v)
			{
				ft_dprintf(1, "\nl1 = \n");
				print_lst(la);
				ft_dprintf(1, "\nl2 = \n\n");
				print_lst(lb);
			}
		}
		ft_strdel(&l);
	}
	if (!check_sort(&la, &lb))
		ft_dprintf(1, "OK\n");
	else
		ft_dprintf(1, "KO\n");
	return (1);
}

int			main(int ac, char **av)
{
	t_lst			*la;
	t_lst			*lb;
	t_info			info;

	if (ac == 1)
	{
		ft_dprintf(1, "./checker [-v] number 0 number 1 ... number n\n");
		return (0);
	}
	info.flag_v = 0;
	if (!ft_strcmp(av[1], "-v"))
		info.flag_v = 1;
	la = create_lst(ac, av);
	lb = NULL;
	if (info.flag_v)
	{
		ft_dprintf(1, "l1 = \n");
		print_lst(la);
		ft_dprintf(1, "\nl2 = \n\n");
		print_lst(lb);
	}
	if (!algo_checker(la, lb, &info))
		return (-1);
	return (0);
}
