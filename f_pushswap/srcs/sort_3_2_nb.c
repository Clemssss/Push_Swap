/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_2_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:52:32 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/17 17:15:49 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_2_nb(t_lst **la, t_info *info, int nb_elem)
{
	while (*la && check_sort(*la, NULL, nb_elem))
	{
		if (nb_elem == 2)
			opperations_list(&(info->la), &(info->lb), "sa", info);
		else if (nb_elem == 3)
		{
			if (((*la)->nb > (*la)->next->nb && (*la)->nb < (*la)->next->next->nb)
					|| ((*la)->nb > (*la)->next->nb && (*la)->nb > (*la)->next->next->nb))
				opperations_list(&(info->la), &(info->lb), "sa", info);
			else
			{
				opperations_list(&(info->la), &(info->lb), "ra", info);
				opperations_list(&(info->la), &(info->lb), "sa", info);
				opperations_list(&(info->la), &(info->lb), "rra", info);
			}
		}
	}
}

void	sort_3_2_nb_rev(t_lst **lb, t_info *info, int nb_elem)
{
	while (*lb && check_sort_rev(*lb, NULL, nb_elem))
	{
		if (nb_elem == 2)
			opperations_list(&(info->la), &(info->lb), "sb", info);
		else if (nb_elem == 3)
		{
			if (((*lb)->nb < (*lb)->next->nb && (*lb)->nb > (*lb)->next->next->nb)
					|| ((*lb)->nb < (*lb)->next->nb && (*lb)->nb < (*lb)->next->next->nb))
				opperations_list(&(info->la), &(info->lb), "sb", info);
			else
			{
				opperations_list(&(info->la), &(info->lb), "rb", info);
				opperations_list(&(info->la), &(info->lb), "sb", info);
				opperations_list(&(info->la), &(info->lb), "rrb", info);
			}
		}
	}
}
