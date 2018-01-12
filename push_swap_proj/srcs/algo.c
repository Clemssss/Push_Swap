/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:10:08 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/12 20:26:26 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_3_2_nb(t_lst **la, t_info *info, int nb_elem)
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

static	void	sort_3_2_nb_rev(t_lst **lb, t_info *info, int nb_elem)
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

static	void	push_in_b(t_info *info, int *count, int recup_end)
{
	int		rev;
	int		i;

	rev = 0;
	i = 0;
	while (info->la && check_nb_exist(info->la, info->mediane))
	{
		if (info->la->nb <= info->mediane)
		{
			*count += 1;
			opperations_list(&(info->la), &(info->lb), "pb", info);
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

static	void	push_in_a(t_info *info, int *count)
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
	while (info->lb && rev < i)
	{
		opperations_list(&(info->la), &(info->lb), "rrb", info);
		rev++;
	}
}

static	void	recup_in_b(t_info *info, int count)
{
	int		i;

	i = 0;
	while (info->lb && i < count)
	{
		opperations_list(&(info->la), &(info->lb), "pa", info);
		i++;
	}
}

static	void	recup_in_a(t_info *info, int count)
{
	int		i;

	i = 0;
	while (info->la && i < count)
	{
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
	info->mediane = fill_mediane(cpy, size);
	push_in_a(info, &count);
	rec_b(info, size - count);
	rec_a(info, count, 1);
	recup_in_a(info, count);
	return (0);
}

int		rec_a(t_info *info, int size, int recup_end)
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
	info->mediane = fill_mediane(cpy, size);
	push_in_b(info, &count, recup_end);
	rec_a(info, size - count, recup_end);
	rec_b(info, count);
	recup_in_b(info, count);
	return (0);
}

static	void	del_maillon(t_lst_op **tmp, int pos)
{
	t_lst_op	*after;
	t_lst_op	*before;
	t_lst_op	*stock;

	after = NULL;
	before = NULL;
	stock = NULL;
	if ((*tmp)->prev && (*tmp)->next->next)
	{
		after = (*tmp)->next->next;
		before = (*tmp)->prev;
		before->next = after;
		after->prev = before;
		if (pos == 0)
			stock = before;
		else if (pos == 1)
			stock = after;
	}
	else if ((*tmp)->prev && !(*tmp)->next->next)
	{
		after = NULL;
		before = (*tmp)->prev;
		before->next = after;
		after->prev = before;
		stock = before;
	}
	else if (!(*tmp)->prev && (*tmp)->next->next)
	{
		after = (*tmp)->next->next;
		before = NULL;
		before->next = after;
		after->prev = before;
		stock = after;
	}
	ft_strdel(&(*tmp)->next->opp);
	ft_strdel(&(*tmp)->opp);
	free((*tmp)->next);
	free((*tmp));
	*tmp = NULL;
	*tmp = stock;
}

static	int		check_del_maillon(t_lst_op **tmp, char *a, char *b)
{
	if ((ft_strcmp((*tmp)->opp, a) == 0 && ft_strcmp((*tmp)->next->opp, b) == 0)
			|| (ft_strcmp((*tmp)->opp, b) == 0 && ft_strcmp((*tmp)->next->opp, a) == 0))
	{
		del_maillon(tmp, 0);
		return (1);
	}
	return (0);
}

static	void	op_inutile(t_info *info)
{
	t_lst_op	*tmp;

	tmp = info->op;
	while (tmp)
	{
		if (tmp->next)
		{
			while (check_del_maillon(&tmp, "pa", "pb"));
			while (check_del_maillon(&tmp, "rra", "ra"));
			while (check_del_maillon(&tmp, "rrb", "rb"));
		}
		tmp = tmp->next;
	}
}

int				algo_push_swap(t_info *info)
{
	rec_a(info, size_lst(info->la), 0);
	op_inutile(info);
	//op_fusion(info);
	if (!info->flag_v)
		print_op(info->op, 0);
	//print_piles(info->la, info->lb);
	return (0);
}
