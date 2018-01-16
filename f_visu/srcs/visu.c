/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:17:22 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/16 17:06:44 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mlx.h"

int				fct_key(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		free_struct_visu(info);
		mlx_destroy_image(info->win->mlx, info->pict->img);
		mlx_destroy_window(info->win->mlx, info->win->window);
		free(info->win);
		free(info->pict);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 49)
		info->space = 1;
	return (1);
}

static	int		init_mlx(t_info *info)
{
	remove_lst(&info->la);
	info->la = NULL;
	info->la = create_lst(info->tab);
	remove_lst(&info->lb);
	info->lb = NULL;
	info->tmp = info->op;
	info->init_height = size_lst(info->la);
	info->init_width = higher_elem(info->la);
	if ((!(info->win = (t_window *)ft_memalloc(sizeof(t_window))))
			|| (!(info->pict = (t_pict *)ft_memalloc(sizeof(t_pict))))
			|| (!(info->iso = (t_pos_iso *)ft_memalloc(sizeof(t_pos_iso))))
			|| (!(info->hsv = (t_hsv *)ft_memalloc(sizeof(t_hsv)))))
		return (0);
	return (1);
}

int				visu(t_info *info)
{
	if ((!(init_mlx(info)))
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
