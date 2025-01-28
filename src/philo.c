/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:32:47 by jcoquet           #+#    #+#             */
/*   Updated: 2024/09/16 08:03:15 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	create_threads(t_table *table)
{
	ssize_t	i;

	i = -1;
	while (++i < table->nb_philos)
	{
		if (pthread_create(&table->philo_ths[i], \
			NULL, &routine, &table->philos[i]) != 0)
			return (1);
	}
	return (0);
}

static int	join_threads(t_table *table)
{
	ssize_t	i;

	i = -1;
	while (++i < table->nb_philos)
	{
		if (pthread_join(table->philo_ths[i], NULL))
			return (printf("join fail"), 1);
	}
	return (0);
}

int	philo_simu(t_table *table)
{
	if (init_data(table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_threads(table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((join_threads(table)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free_data(table);
	return (EXIT_SUCCESS);
}
