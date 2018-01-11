/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:53:19 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/11 23:51:31 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	init_struct(t_info *info, int ac, char **av)
{
	info->mediane = 0;
	info->flag_v = 0;
	info->coup = 0;
	if (!ft_strcmp(av[1], "-v"))
		info->flag_v = 1;
	info->la = create_lst(ac, av);
	info->lb = NULL;
	info->last = NULL;
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

	if (ac == 1)
	{
		ft_dprintf(1, "./push_swap [-v] number 0 number 1 ... number n\n");
		return (0);
	}
	init_struct(&info, ac, av);
	if (size_lst(info.la) < 7)
		algo_inf_7(&info);
	else
		algo_push_swap(&info);
	return (0);
}
