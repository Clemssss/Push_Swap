/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:52:05 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/15 18:40:16 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		algo_checker(t_info *info)
{
	char	*l;
	int		ret;

	l = NULL;
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
			remove_lst(&info->la);
			remove_lst(&info->lb);
			exit(EXIT_FAILURE);
		}
		else
			opperations_list(&(info->la), &(info->lb), l, info);
		ft_strdel(&l);
	}
	if (!check_sort(info->la, info->lb, size_lst(info->la)))
		ft_dprintf(1, "OK\n");
	else
		ft_dprintf(1, "KO\n");
	return (1);
}

static	void	init_struct_checker(t_info *info, char **av)
{
	info->mediane = 0;
	info->flag_v = 0;
	info->coup = 0;
	if (!ft_strcmp(av[0], "-v"))
		info->flag_v = 1;
	info->la = create_lst(av);
	info->lb = NULL;
	info->last = NULL;
	info->tail = NULL;
	info->op = NULL;
	if (info->flag_v)
	{
		ft_dprintf(1, "l1 : ");
		print_lst(info->la);
		ft_dprintf(1, "\nl2 : \n\n");
		print_lst(info->lb);
	}
}

int				main(int ac, char **av)
{
	t_info			info;

	info.tab = NULL;
	if (ac == 1)
	{
		ft_dprintf(1, "./checker [-v] number 0 number 1 ... number n\n");
		return (0);
	}
	if (check_string_av(av[1]))
		info.tab = ft_strsplit(av[1], ' ');
	else
		info.tab = ft_tabcpy(av, 1);
	init_struct_checker(&info, info.tab);
	if (!algo_checker(&info))
		return (-1);
	return (0);
}
