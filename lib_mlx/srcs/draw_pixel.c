/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:43:25 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/14 17:18:44 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void	draw_pixel(t_pict *pict, int x, int y)
{
	pict->data[y * pict->size_line + x * pict->bpp / 8] = pict->b;
	pict->data[y * pict->size_line + x * pict->bpp / 8 + 1] = pict->g;
	pict->data[y * pict->size_line + x * pict->bpp / 8 + 2] = pict->r;
}
