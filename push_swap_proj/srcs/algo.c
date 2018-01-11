/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:10:08 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/11 23:51:30 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_3_2_nb(t_lst **la, t_info *info, int nb_elem)
{
	while (check_sort(*la, NULL, nb_elem))
	{
		ft_dprintf(1, "here sort_3_2_nb, size = %d, mediane = %d\n", nb_elem, info->mediane);
		if (nb_elem == 2)
			opperations_list(&(info->la), &(info->lb), "sa", info);
		else if (nb_elem == 3)
		{
			if (((*la)->nb > (*la)->next->nb && (*la)->nb < (*la)->next->next->nb)
					|| ((*la)->nb > (*la)->next->nb && (*la)->nb > (*la)->next->next->nb
						&& (*la)->next->nb < (*la)->next->next->nb))
				opperations_list(&(info->la), &(info->lb), "sa", info);
			else if (((*la)->nb < (*la)->next->nb && (*la)->nb < (*la)->next->next->nb)
					|| ((*la)->nb > (*la)->next->nb && (*la)->nb > (*la)->next->next->nb
						&& (*la)->next->nb > (*la)->next->next->nb))
			{
				opperations_list(&(info->la), &(info->lb), "ra", info);
				opperations_list(&(info->la), &(info->lb), "sa", info);
				opperations_list(&(info->la), &(info->lb), "rra", info);	
			}
		}
	}
}

static	void	sort_3_2_nb_rev(t_lst **lb, t_info *info, int nb_elem)
{
	while (check_sort_rev(*lb, NULL, nb_elem))
	{
		ft_dprintf(1, "here sort_3_2_nb_rev, size = %d, mediane = %d\n", nb_elem, info->mediane);
		if (nb_elem == 2)
			opperations_list(&(info->la), &(info->lb), "sb", info);
		else if (nb_elem == 3)
		{
			if (((*lb)->nb < (*lb)->next->nb && (*lb)->nb > (*lb)->next->next->nb)
					|| ((*lb)->nb < (*lb)->next->nb && (*lb)->nb < (*lb)->next->next->nb
						&& (*lb)->next->nb < (*lb)->next->next->nb))
				opperations_list(&(info->la), &(info->lb), "sb", info);
			else if (((*lb)->nb > (*lb)->next->nb && (*lb)->nb > (*lb)->next->next->nb)
					|| ((*lb)->nb < (*lb)->next->nb && (*lb)->nb < (*lb)->next->next->nb
						&& (*lb)->next->nb < (*lb)->next->next->nb))
			{
				opperations_list(&(info->la), &(info->lb), "rb", info);
				opperations_list(&(info->la), &(info->lb), "sb", info);
				opperations_list(&(info->la), &(info->lb), "rrb", info);	
			}
		}
	}
}

static	void	push_in_b(t_info *info, int *count)
{
	int		rev;

	rev = 0;
	while (check_nb_exist(info->la, info->mediane))
	{
		ft_dprintf(1, "here push_in_b, mediane = %d\n", info->mediane);
		if (info->la->nb <= info->mediane)
			opperations_list(&(info->la), &(info->lb), "pb", info);
		else
		{
			*count += 1;
			opperations_list(&(info->la), &(info->lb), "ra", info);
		}
	}
	while (rev < *count)
	{
		opperations_list(&(info->la), &(info->lb), "rra", info);
		rev++;
	}
}

static	void	push_in_a(t_info *info, int *count)
{
	int		rev;

	rev = 0;
	while (check_nb_exist_rev(info->lb, info->mediane))
	{
		ft_dprintf(1, "here push_in_a, mediane = %d\n", info->mediane);
		if (info->lb->nb > info->mediane)
			opperations_list(&(info->la), &(info->lb), "pa", info);
		else
		{
			*count += 1;
			opperations_list(&(info->la), &(info->lb), "rb", info);
		}
	}
	ft_dprintf(1, "pre rev %d\n", rev);
	while (rev < *count)
	{
		opperations_list(&(info->la), &(info->lb), "rrb", info);
		rev++;
	}
}

static	void	recup_in_b(t_info *info, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		ft_dprintf(1, "here recup_in_b, count = %d,mediane = %d\n", count, info->mediane);
		opperations_list(&(info->la), &(info->lb), "pa", info);
		i++;
	}
}

static	void	recup_in_a(t_info *info, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		ft_dprintf(1, "here recup_in_a, count = %d,mediane = %d\n", count, info->mediane);
		opperations_list(&(info->la), &(info->lb), "pb", info);
		i++;
	}
}

int		rec_b(t_info *info, int size)
{
	t_lst	*cpy;
	int		count;

	count = 0;
	if (size <= 3)
	{
		sort_3_2_nb_rev(&(info->lb), info, size);
		return (0);
	}
	cpy = cpy_lst(&(info->lb));
	info->mediane = fill_mediane(info->lb, size);
	ft_dprintf(1, "MEDIAAAAAAAAANE  = %d\n", info->mediane);
	info->lb = cpy;
	ft_dprintf(1, "here rec_b, size = %d, mediane = %d\n", size, info->mediane);
	push_in_a(info, &count);
	ft_dprintf(1, "post rev\n");
	rec_b(info, size_lst(info->lb));
	rec_a(info, size - count);
	recup_in_a(info, size - count);
	return (0);
}

int		rec_a(t_info *info, int size)
{
	int		count;
	t_lst	*cpy;

	count = 0;
	if (size <= 3)
	{
		sort_3_2_nb(&(info->la), info, size);
		return (0);
	}
	cpy = cpy_lst(&(info->la));
	info->mediane = fill_mediane(info->la, size);
	ft_dprintf(1, "MEDIAAAAAAAAANE  = %d\n", info->mediane);
	info->la = cpy;
	push_in_b(info, &count);
	ft_dprintf(1, "here rec_a, size = %d, mediane = %d\n", size, info->mediane);
	rec_a(info, size_lst(info->la));
	rec_b(info, size - count);
	recup_in_b(info, size - count);
	return (0);
}

int				algo_push_swap(t_info *info)
{
	rec_a(info, size_lst(info->la));
	print_piles(info->la, info->lb);
	return (0);
}
