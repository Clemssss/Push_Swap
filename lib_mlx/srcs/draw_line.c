/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:42:59 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/14 17:01:26 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

static	void	draw_x(t_pict *pict, t_line *line)
{
	int			i;
	int			cumul;

	cumul = line->diff_x / 2;
	i = 0;
	while (i < line->diff_x)
	{
		line->x += line->x_incr;
		cumul += line->diff_y;
		if (cumul >= line->diff_x)
		{
			cumul -= line->diff_x;
			line->y += line->y_incr;
		}
		if ((line->x >= 0 && line->x < WIDTH)
				&& (line->y >= 1 && line->y < HEIGHT))
			draw_pixel(pict, line->x, line->y);
		i++;
	}
}

static	void	draw_y(t_pict *pict, t_line *line)
{
	int			i;
	int			cumul;

	cumul = line->diff_y / 2;
	i = 0;
	while (i < line->diff_y)
	{
		line->y += line->y_incr;
		cumul += line->diff_x;
		if (cumul >= line->diff_y)
		{
			cumul -= line->diff_y;
			line->x += line->x_incr;
		}
		if ((line->x >= 0 && line->x < WIDTH)
				&& (line->y >= 1 && line->y < HEIGHT))
			draw_pixel(pict, line->x, line->y);
		i++;
	}
}

void			draw_line(t_pict *pict, t_pos_iso *pos_iso)
{
	t_line		line;

	line.x = pos_iso->xmin;
	line.y = pos_iso->ymin;
	line.diff_x = pos_iso->xmax - pos_iso->xmin;
	line.diff_y = pos_iso->ymax - pos_iso->ymin;
	line.x_incr = (line.diff_x > 0) ? 1 : -1;
	line.y_incr = (line.diff_y > 0) ? 1 : -1;
	line.diff_x = ABS(line.diff_x);
	line.diff_y = ABS(line.diff_y);
	if ((line.x >= 0 && line.x < WIDTH)
			&& (line.y >= 1 && line.y < HEIGHT))
		draw_pixel(pict, line.x, line.y);
	if (line.diff_x > line.diff_y)
		draw_x(pict, &line);
	else
		draw_y(pict, &line);
}
