/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:33:51 by clegirar          #+#    #+#             */
/*   Updated: 2018/01/19 18:03:10 by clegirar         ###   ########.fr       */
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

static	void	add_maillon(t_lst **la, char **av, int i, long long nb)
{
	t_lst			*tmp;
	t_lst			*tmp2;

	tmp = new_maillon(nb);
	*la = tmp;
	tmp2 = tmp;
	while (av[i])
	{
		nb = ft_atol_ps(av[i]);
		if (nb > INT_MAX || nb < INT_MIN
				|| !check_nb_lst(*la, nb) || !check_av(av[i]))
		{
			ft_dprintf(2, "Error\n");
			remove_lst(la);
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
}

t_lst			*create_lst(char **av)
{
	t_lst			*la;
	int				i;
	long	long	nb;

	i = 0;
	if (!ft_strcmp(av[i], "-v"))
		i++;
	nb = ft_atol_ps(av[i]);
	if (nb > INT_MAX || nb < INT_MIN || !check_av(av[i++]))
	{
		ft_dprintf(2, "Error\n");
		exit(EXIT_FAILURE);
	}
	add_maillon(&la, av, i, nb);
	return (la);
}
