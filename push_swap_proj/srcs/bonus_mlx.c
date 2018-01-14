/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:14:09 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/14 18:15:26 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mlx.h"

//	KEYCODE SPACE = 49

int		fct_key(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		free_struct(info);
		mlx_destroy_image(info->win->mlx, info->pict->img);
		mlx_destroy_window(info->win->mlx, info->win->window);
		free(info->win);
		free(info->pict);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int		do_change(t_info *info)
{
	(void)info;
	return (1);
}

int		bonus_mlx(t_info *info)
{
	if ((!(info->win = (t_window *)ft_memalloc(sizeof(t_window))))
			|| (!(info->pict = (t_pict *)ft_memalloc(sizeof(t_pict))))
			|| (!(info->win->mlx = mlx_init())))
		return (0);
	info->win->width = WIDTH;
	info->win->height = HEIGHT;
	info->pict->x = WIDTH;
	info->pict->y = HEIGHT;
	if ((!(info->win->window = mlx_new_window(info->win->mlx,
						info->win->width, info->win->height, NAME)))
			|| (!(info->pict->img = mlx_new_image(info->win->mlx,
						info->pict->x, info->pict->y)))
			|| (!(info->pict->data = mlx_get_data_addr(info->pict->img,
						&info->pict->bpp, &info->pict->size_line,
						&info->pict->endian))))
		return (0);
	mlx_hook(info->win->window, 2, 0, &fct_key, info);
	mlx_loop_hook(info->win->mlx, &do_change, info);
	mlx_loop(info->win->mlx);
	return (1);
}
