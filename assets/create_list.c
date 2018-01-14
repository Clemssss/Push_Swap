/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:33:51 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/14 18:13:40 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int		check_nb_lst(t_lst *la, long long nb)
{
	t_lst	*tmp;

	if (!la)
		return (-1);
	tmp = la;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static	int		check_av(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

t_lst			*create_lst(int ac, char **av)
{
	t_lst			*la;
	t_lst			*tmp;
	t_lst			*tmp2;
	int				i;
	long	long	nb;

	i = 1;
	if (!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-n"))
		i++;
	nb = ft_atol_ps(av[i]);
	if (nb > INT_MAX || nb < INT_MIN || !check_av(av[i++]))
	{
		ft_dprintf(2, "Error\n");
		exit(EXIT_FAILURE);
	}
	tmp = new_maillon(nb);
	la = tmp;
	tmp2 = tmp;
	while (i < ac)
	{
		nb = ft_atol_ps(av[i]);
		if (nb > INT_MAX || nb < INT_MIN
				|| !check_nb_lst(la, nb) || !check_av(av[i]))
		{
			ft_dprintf(2, "Error\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			tmp = new_maillon(nb);
			tmp2->next = tmp;
			tmp2 = tmp;
		}
		i++;
	}
	return (la);
}
