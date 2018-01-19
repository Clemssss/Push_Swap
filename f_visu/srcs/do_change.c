/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:21:40 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 19:02:06 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mlx.h"

static	void	make(t_info *info)
{
	t_lst	*tmp_la;
	t_lst	*tmp_lb;
	int		i;

	line_mid(info);
	tmp_la = info->la;
	tmp_lb = info->lb;
	i = HEIGHT;
	while (tmp_la)
	{
		print_line_la(info, tmp_la->nb, i);
		tmp_la = tmp_la->next;
		i = i - (HEIGHT / info->init_height);
	}
	i = HEIGHT;
	while (tmp_lb)
	{
		print_line_lb(info, tmp_lb->nb, i);
		tmp_lb = tmp_lb->next;
		i = i - (HEIGHT / info->init_height);
	}
}

static	char	*rev_op(char *opp)
{
	if (!ft_strcmp(opp, "pa"))
		return ("pb");
	else if (!ft_strcmp(opp, "pb"))
		return ("pa");
	else if (!ft_strcmp(opp, "ra"))
		return ("rra");
	else if (!ft_strcmp(opp, "rb"))
		return ("rrb");
	else if (!ft_strcmp(opp, "rra"))
		return ("ra");
	else if (!ft_strcmp(opp, "rrb"))
		return ("rb");
	else if (!ft_strcmp(opp, "rr"))
		return ("rrr");
	else if (!ft_strcmp(opp, "rrr"))
		return ("rr");
	else if (!ft_strcmp(opp, "ss"))
		return ("ss");
	return (opp);
}

int				do_change(t_info *info)
{
	if (info->tmp && info->space)
	{
		call_op(&info->la, &info->lb, info->tmp->opp);
		info->tmp = info->tmp->next;
	}
	else if (info->key[123] && info->tmp && info->tmp->prev)
	{
		info->tmp = info->tmp->prev;
		call_op(&info->la, &info->lb, rev_op(info->tmp->opp));
	}
	else if (info->key[124] && info->tmp && info->tmp->next)
	{
		call_op(&info->la, &info->lb, info->tmp->opp);
		info->tmp = info->tmp->next;
	}
	clear_pixels(info->pict);
	make(info);
	mlx_put_image_to_window(info->win->mlx,
			info->win->window, info->pict->img, 0, 0);
	return (1);
}
