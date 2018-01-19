/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_recup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:40:21 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 18:55:26 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	worst_case(t_lst **la, t_info *info, int *nb_elem)
{
	if (*la && (*la)->next && (*la)->next->next
			&& (*la)->next->next->nb < (*la)->next->nb
			&& (*la)->next->next->nb < (*la)->nb)
	{
		opperations_list(&(info->la), &(info->lb), "ra", info);
		opperations_list(&(info->la), &(info->lb), "sa", info);
		opperations_list(&(info->la), &(info->lb), "pb", info);
		info->count_b += 1;
		*nb_elem -= 1;
		opperations_list(&(info->la), &(info->lb), "rra", info);
	}
}

static	void	loop(t_lst **la, t_info *info, int *nb_elem)
{
	while (*la && check_sort(*la, NULL, *nb_elem))
	{
		if (*nb_elem == 2 && check_sort(*la, NULL, *nb_elem))
			opperations_list(&(info->la), &(info->lb), "sa", info);
		else if (*la && (*la)->next && (*la)->next->next
				&& (*la)->nb < (*la)->next->nb
				&& (*la)->nb < (*la)->next->next->nb)
		{
			info->count_b += 1;
			*nb_elem -= 1;
			opperations_list(&(info->la), &(info->lb), "pb", info);
		}
		else if (*la && (*la)->next && (*la)->next->next
				&& (*la)->next->nb < (*la)->nb
				&& (*la)->next->nb < (*la)->next->next->nb)
			opperations_list(&(info->la), &(info->lb), "sa", info);
		else
			worst_case(la, info, nb_elem);
	}
}

void			sort_and_recup(t_lst **la, t_info *info, int nb_element)
{
	int		nb_elem;

	nb_elem = nb_element;
	if (nb_elem == 2)
	{
		if (*la && check_sort(*la, NULL, nb_elem))
			opperations_list(&(info->la), &(info->lb), "sa", info);
	}
	else if (nb_elem == 3)
		loop(la, info, &nb_elem);
	if (nb_elem == 2)
	{
		info->count_b += 2;
		opperations_list(&(info->la), &(info->lb), "pb", info);
		opperations_list(&(info->la), &(info->lb), "pb", info);
	}
	else if (nb_elem == 3)
	{
		info->count_b += 3;
		opperations_list(&(info->la), &(info->lb), "pb", info);
		opperations_list(&(info->la), &(info->lb), "pb", info);
		opperations_list(&(info->la), &(info->lb), "pb", info);
	}
}
