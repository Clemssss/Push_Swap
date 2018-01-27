/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hsv_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:21:19 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/09 19:53:28 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

static	void	h_0_to_3(double h, double v, t_color *color)
{
	if (h < 1)
	{
		color->red = v;
		color->green = color->up;
		color->blue = color->min;
	}
	else if (h >= 1 && h < 2)
	{
		color->red = color->down;
		color->green = v;
		color->blue = color->min;
	}
	else if (h >= 2 && h < 3)
	{
		color->red = color->min;
		color->green = v;
		color->blue = color->up;
	}
}

static	void	h_3_to_6(double h, double v, t_color *color)
{
	if (h >= 3 && h < 4)
	{
		color->red = color->min;
		color->green = color->down;
		color->blue = v;
	}
	else if (h >= 4 && h < 5)
	{
		color->red = color->up;
		color->green = color->min;
		color->blue = v;
	}
	else if (h >= 5 && h < 6)
	{
		color->red = v;
		color->green = color->min;
		color->blue = color->down;
	}
}

void			conv_hsv_rgb(t_pict *pict, float h, float s, float v)
{
	t_color		color;

	h = h * 3.14 / 180;
	color.i = (int)h;
	color.f = h - color.i;
	color.min = v * (1 - s);
	color.down = v * (1 - color.f * s);
	color.up = v * (1 - (1 - color.f) * s);
	if (h >= 0 && h < 3)
		h_0_to_3(h, v, &color);
	else if (h >= 3 && h < 6)
		h_3_to_6(h, v, &color);
	else if (h > 6)
	{
		color.red = v;
		color.green = color.min;
		color.blue = color.up;
	}
	pict->r = color.red * 255;
	pict->g = color.green * 255;
	pict->b = color.blue * 255;
}
