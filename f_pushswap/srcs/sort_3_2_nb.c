/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_2_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:52:32 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 16:42:30 by clegirar         ###   ########.fr       */
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

void	sort_and_recup(t_lst **la, t_info *info, int nb_element)
{
	int		nb_elem;

	nb_elem = nb_element;
	if (nb_elem == 2)
	{
		if (*la && check_sort(*la, NULL, nb_elem))
			opperations_list(&(info->la), &(info->lb), "sa", info);
		info->count_b += 2;
		opperations_list(&(info->la), &(info->lb), "pb", info);
		opperations_list(&(info->la), &(info->lb), "pb", info);
	}
	else if (nb_elem == 3)
	{
		while (*la && check_sort(*la, NULL, nb_elem))
		{
			if (nb_elem == 2 && check_sort(*la, NULL, nb_elem))
				opperations_list(&(info->la), &(info->lb), "sa", info);
			else if (*la && (*la)->next && (*la)->next->next
					&& (*la)->nb < (*la)->next->nb
					&& (*la)->nb < (*la)->next->next->nb)
			{
				info->count_b += 1;
				nb_elem--;
				opperations_list(&(info->la), &(info->lb), "pb", info);
			}
			else if (*la && (*la)->next && (*la)->next->next
					&& (*la)->next->nb < (*la)->nb
					&& (*la)->next->nb < (*la)->next->next->nb)
				opperations_list(&(info->la), &(info->lb), "sa", info);
			else if (*la && (*la)->next && (*la)->next->next
					&& (*la)->next->next->nb < (*la)->next->nb
					&& (*la)->next->next->nb < (*la)->nb)
			{
				opperations_list(&(info->la), &(info->lb), "ra", info);
				opperations_list(&(info->la), &(info->lb), "sa", info);
				opperations_list(&(info->la), &(info->lb), "pb", info);
				info->count_b += 1;
				nb_elem--;
				opperations_list(&(info->la), &(info->lb), "rra", info);
			}
		}
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

void	sort_rev_and_recup(t_lst **la, t_info *info, int nb_element)
{
	int		nb_elem;

	nb_elem = nb_element;
	if (nb_elem == 2)
	{
		if (*la && check_sort_rev(*la, NULL, nb_elem))
			opperations_list(&(info->la), &(info->lb), "sb", info);
		info->count_a += 2;
		opperations_list(&(info->la), &(info->lb), "pa", info);
		opperations_list(&(info->la), &(info->lb), "pa", info);
	}
	else if (nb_elem == 3)
	{
		while (*la && check_sort_rev(*la, NULL, nb_elem))
		{
			if (nb_elem == 2 && check_sort_rev(*la, NULL, nb_elem))
				opperations_list(&(info->la), &(info->lb), "sb", info);
			else if (*la && (*la)->next && (*la)->next->next
					&& (*la)->nb > (*la)->next->nb
					&& (*la)->nb > (*la)->next->next->nb)
			{
				nb_elem--;
				info->count_a += 1;
				opperations_list(&(info->la), &(info->lb), "pa", info);
			}
			else if (*la && (*la)->next && (*la)->next->next
					&& (*la)->next->nb > (*la)->nb
					&& (*la)->next->nb > (*la)->next->next->nb)
				opperations_list(&(info->la), &(info->lb), "sb", info);
			else if (*la && (*la)->next && (*la)->next->next
					&& (*la)->next->next->nb > (*la)->next->nb
					&& (*la)->next->next->nb > (*la)->nb)
			{
				opperations_list(&(info->la), &(info->lb), "rb", info);
				opperations_list(&(info->la), &(info->lb), "sb", info);
				opperations_list(&(info->la), &(info->lb), "pa", info);
				info->count_a += 1;
				nb_elem--;
				opperations_list(&(info->la), &(info->lb), "rrb", info);
			}
		}
		if (nb_elem == 2)
		{
			info->count_a += 2;
			opperations_list(&(info->la), &(info->lb), "pa", info);
			opperations_list(&(info->la), &(info->lb), "pa", info);
		}
		else if (nb_elem == 3)
		{
			info->count_a += 3;
			opperations_list(&(info->la), &(info->lb), "pa", info);
			opperations_list(&(info->la), &(info->lb), "pa", info);
			opperations_list(&(info->la), &(info->lb), "pa", info);
		}
	}
}
