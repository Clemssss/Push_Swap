/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:07:05 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/16 23:09:54 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			free_struct_visu(t_info *info)
{
	ft_tabdel(info->tab);
	remove_lst(&info->la);
	remove_lst_op(&info->op);
	info->last = NULL;
}


static	int		fill_op(t_info *info)
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
	return (1);
}

static	void	init_struct_visu(t_info *info, char **av)
{
	info->la = create_lst(av);
	info->lb = NULL;
	info->tail = NULL;
	info->op = NULL;
}

int				main(int ac, char **av)
{
	t_info	info;

	info.tab = NULL;
	if (ac == 1)
	{
		ft_dprintf(1, "./visu number 0 number 1 ... number n\n");
		return (0);
	}
	if (check_string_av(av[1]))
		info.tab = ft_strsplit(av[1], ' ');
	else
		info.tab = ft_tabcpy(av, 1);
	init_struct_visu(&info, info.tab);
	if (!fill_op(&info) || !visu(&info))
		return (-1);
	free_struct_visu(&info);
	return (0);
}
