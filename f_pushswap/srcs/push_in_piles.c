/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_piles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:49:52 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 16:42:31 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_b(t_info *info, int *count, int recup_end)
{
	int		rev;
	int		i;

	rev = 0;
	i = 0;
	while (info->la && check_nb_exist(info->la, info->mediane))
	{
		if (info->la->nb <= info->mediane)
		{
			opperations_list(&(info->la), &(info->lb), "pb", info);
			*count += 1;
		}
		else
		{
			i++;
			opperations_list(&(info->la), &(info->lb), "ra", info);
		}
	}
	while (info->la && rev < i && recup_end)
	{
		opperations_list(&(info->la), &(info->lb), "rra", info);
		rev++;
	}
}

void	push_in_a(t_info *info, int *count, int recup_b)
{
	int		rev;
	int		i;

	rev = 0;
	i = 0;
	while (info->lb && check_nb_exist_rev(info->lb, info->mediane))
	{
		if (info->lb->nb >= info->mediane)
		{
			opperations_list(&(info->la), &(info->lb), "pa", info);
			*count += 1;
		}
		else
		{
			i++;
			opperations_list(&(info->la), &(info->lb), "rb", info);
		}
	}
	while (info->lb && rev < i && recup_b)
	{
		opperations_list(&(info->la), &(info->lb), "rrb", info);
		rev++;
	}
}
