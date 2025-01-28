/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:01:32 by jcoquet           #+#    #+#             */
/*   Updated: 2024/09/10 15:33:55 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	init_forks(t_table *table)
{
	ssize_t		i;
	t_philo		*philos;

	philos = table->philos;
	i = -1;
	while (++i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (printf("mutex fail"), 1);
	}
	i = 0;
	philos[0].left_f = &table->forks[0];
	philos[0].right_f = &table->forks[table->nb_philos - 1];
	while (++i < table->nb_philos)
	{
		philos[i].left_f = &table->forks[i];
		philos[i].right_f = &table->forks[i - 1];
	}
	return (0);
}

int	init_philos(t_table *table)
{
	ssize_t		i;
	size_t		start = get_timestamp_in_ms();

	i = -1;
	while (++i < table->nb_philos)
	{
		table->philos[i].data.nb_philos = table->nb_philos;
		table->philos[i].data.time_to_eat = table->time_to_eat;
		table->philos[i].data.time_to_die = table->time_to_die;
		table->philos[i].data.time_to_sleep = table->time_to_sleep;
		table->philos[i].data.nb_of_times_to_eat = table->nb_of_times_to_eat;
		table->philos[i].id = i + 1;
		table->philos[i].nb_meals_had = 0;
		table->philos[i].data.start_time = start;
		table->philos[i].table = table;
	}
	return (0);
}

static int	init_other_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->m_print, NULL))
		return (printf("mutex fail"), 1);
	if (pthread_mutex_init(&table->m_is_dead, NULL))
		return (printf("mutex fail"), 1);
	return (EXIT_SUCCESS);
}

static int	init_malloc(t_table *table)
{
	table->philos = malloc(sizeof(t_philo) * table->nb_philos);
	if (!table->philos)
		return (printf("Malloc error"), EXIT_FAILURE);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philos);
	if (!table->forks)
		return (free(table->philos), printf("Malloc error"), EXIT_FAILURE);
	table->philo_ths = malloc(sizeof(pthread_t) * table->nb_philos);
	if (!table->philo_ths)
	{
		free(table->philos);
		free(table->forks);
		return (printf("Malloc error"), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_data(t_table *table)
{
	if (!table)
		return (EXIT_FAILURE);
	if (init_malloc(table))
		return (printf("malloc_fail"), EXIT_FAILURE);
	if (init_philos(table))
		return (EXIT_FAILURE);
	if (init_forks(table))
		return (EXIT_FAILURE);
	if (init_other_mutex(table))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
