/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:21:40 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/18 14:14:01 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mlx.h"

static	void	print_line_la(t_info *info, int nb, int i)
{
	int		j;

	j = i - (HEIGHT / info->init_height);
	while (j < i)
	{
		info->iso->xmin = 0;
		info->iso->ymin = j;
		info->iso->xmax = neme_elem(info->ordre, nb)
			* ((WIDTH / 2) / info->init_height);
		info->iso->ymax = j;
		conv_hsv_rgb(info->pict,
				(float)neme_elem(info->ordre, nb) * info->pas_h, 1, 1);
		draw_line(info->pict, info->iso);
		j++;
	}
}

static	void	print_line_lb(t_info *info, int nb, int i)
{
	int		j;

	j = i - (HEIGHT / info->init_height);
	while (j < i)
	{
		info->iso->xmin = WIDTH / 2;
		info->iso->ymin = j;
		info->iso->xmax = neme_elem(info->ordre, nb)
			* ((WIDTH / 2) / info->init_height) + WIDTH / 2;
		info->iso->ymax = j;
		conv_hsv_rgb(info->pict,
				(float)neme_elem(info->ordre, nb) * info->pas_h, 1, 1);
		draw_line(info->pict, info->iso);
		j++;
	}
}

static	void	line_mid(t_info *info)
{
	info->iso->xmin = WIDTH / 2;
	info->iso->ymin = 0;
	info->iso->xmax = WIDTH / 2;
	info->iso->ymax = HEIGHT;
	conv_hsv_rgb(info->pict, 0, 1, 1);
	draw_line(info->pict, info->iso);
}

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
