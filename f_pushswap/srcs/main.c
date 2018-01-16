/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:53:19 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/16 22:46:36 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	init_struct(t_info *info, char **av)
{
	info->mediane = 0;
	info->flag_v = 0;
	info->space = 0;
	info->flag_n = 0;
	info->coup = 0;
	if (!ft_strcmp(av[0], "-v"))
		info->flag_v = 1;
	else if (!ft_strcmp(av[0], "-n"))
		info->flag_n = 1;
	info->la = create_lst(av);
	info->lb = NULL;
	info->tmp = NULL; 
	info->op = NULL;
	info->tail = NULL;
}

void			free_struct(t_info *info)
{
	info->space = 0;
	info->mediane = 0;
	info->flag_v = 0;
	info->flag_n = 0;
	info->coup = 0;
	ft_tabdel(info->tab);
	remove_lst(&info->la);
	remove_lst_op(&info->op);
	info->last = NULL;
}

static	void	print_flag_v(t_info *info)
{
	remove_lst(&info->la);
	info->la = NULL;
	info->la = create_lst(info->tab);
	remove_lst(&info->lb);
	info->lb = NULL;
	info->tmp = info->op;
	while (info->tmp)
	{
		call_op(&info->la, &info->lb, info->tmp->opp);
		ft_dprintf(1, "%s\nla : ", info->tmp->opp);
		print_lst(info->la);
		ft_dprintf(1, "\nlb : ");
		print_lst(info->lb);
		ft_dprintf(1, "\n\n");
		info->tmp = info->tmp->next;
	}
}

int				main(int ac, char **av)
{
	t_info		info;

	info.tab = NULL;
	if (ac == 1)
	{
		ft_dprintf(1, "./push_swap [-v / -n] number 0 number 1 ... number n\n");
		return (0);
	}
	if (check_string_av(av[1]))
		info.tab = ft_strsplit(av[1], ' ');
	else
		info.tab = ft_tabcpy(av, 1);
	init_struct(&info, info.tab);
	if (size_lst(info.la) < 7)
		algo_inf_7(&info);
	else
		algo_push_swap(&info);
	if (info.flag_v)
		print_flag_v(&info);
	else if (info.flag_n)
		bonus_mlx(&info, info.tab);
	free_struct(&info);
	return (0);
}
