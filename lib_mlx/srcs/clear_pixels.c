/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:42:24 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/09 19:52:23 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void	clear_pixels(t_pict *pict)
{
	int	x;
	int	y;

	y = 0;
	while (y < pict->y)
	{
		x = 0;
		while (x < pict->x)
		{
			pict->data[y * pict->size_line + x * pict->bpp / 8] = 0;
			pict->data[y * pict->size_line + x * pict->bpp / 8 + 1] = 0;
			pict->data[y * pict->size_line + x * pict->bpp / 8 + 2] = 0;
			x++;
		}
		y++;
	}
}
