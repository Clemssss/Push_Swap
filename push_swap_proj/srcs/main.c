/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:53:19 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/10 23:03:24 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (size_lst(la) < 7)
	{
		if (!algo_inf_7(&la, &lb, &info))
			return (-1);
	}
	else
		algo_push_swap(&la, &lb, &info, create_lst(ac, av));
	return (0);
}
