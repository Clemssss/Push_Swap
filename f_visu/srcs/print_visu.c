/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_visu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:58:17 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 19:02:05 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_line_la(t_info *info, int nb, int i)
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

void	print_line_lb(t_info *info, int nb, int i)
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

void	line_mid(t_info *info)
{
	info->iso->xmin = WIDTH / 2;
	info->iso->ymin = 0;
	info->iso->xmax = WIDTH / 2;
	info->iso->ymax = HEIGHT;
	conv_hsv_rgb(info->pict, 0, 1, 1);
	draw_line(info->pict, info->iso);
}
