/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_in_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:51:48 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 16:42:32 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recup_in_b(t_info *info, int count)
{
	int		i;

	i = 0;
	while (info->lb && i < count)
	{
		opperations_list(&(info->la), &(info->lb), "pa", info);
		i++;
	}
}

void	recup_in_a(t_info *info, int count)
{
	int		i;

	i = 0;
	while (info->la && i < count)
	{
		opperations_list(&(info->la), &(info->lb), "pb", info);
		i++;
	}
}
