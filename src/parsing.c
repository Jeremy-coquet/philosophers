/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:37:44 by jcoquet           #+#    #+#             */
/*   Updated: 2024/09/05 17:30:34 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static bool	is_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (false);
		}
	}
	return (true);
}

bool	check_input(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (false);
	if (!is_digit(av))
		return (false);
	return (true);
}

static bool	check_parameters(t_table *table)
{
	if (table->nb_philos == 0 || table->nb_philos > 200)
		return (false);
	if (table->time_to_die < 60)
		return (false);
	if (table->time_to_eat < 60)
		return (false);
	if (table->time_to_sleep < 60)
		return (false);
	if (table->nb_of_times_to_eat == 0)
		return (false);
	return (true);
}

bool	set_parameters(t_table *table, char **av)
{
	table->nb_philos = ft_atost(av[1]);
	table->time_to_die = ft_atost(av[2]);
	table->time_to_eat = ft_atost(av[3]);
	table->time_to_sleep = ft_atost(av[4]);
	if (av[5] != NULL)
		table->nb_of_times_to_eat = ft_atost(av[5]);
	else
		table->nb_of_times_to_eat = 999999999999999999;
	if (!check_parameters(table))
		return (false);
	return (true);
}
