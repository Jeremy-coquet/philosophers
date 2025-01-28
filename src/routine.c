/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:21:34 by jcoquet           #+#    #+#             */
/*   Updated: 2024/09/10 15:35:32 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	check_death(t_philo *philo)
{
	size_t	death_angel_time;

	death_angel_time = philo->last_eat_time + philo->data.time_to_die;
	// printf("%sdeath_angel_time %zu%s\n", RED, death_angel_time - philo->data.start_time, RST);
	// printf("%sgettimestemp%zu%s\n", GREEN, get_timestamp_in_ms() - philo->data.start_time, RST);
	if (get_timestamp_in_ms() > death_angel_time)
	{
		// printf("%sdeath_angel_time %zu%s\n", RED, death_angel_time - philo->data.start_time, RST);
		// printf("%sgettimestemp%zu%s\n", GREEN, get_timestamp_in_ms() - philo->data.start_time, RST);
		if (get_is_dead(philo) == true)
			return (true);
		else
		{
			pthread_mutex_lock(&philo->table->m_print);
			philo->table->is_dead = true;
			print_action(philo, DIED);
			pthread_mutex_unlock(&philo->table->m_print);
			return (true);
		}
	}
	return (false);
}

bool	get_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->m_is_dead);
	if (philo->table->is_dead == true)
		return (pthread_mutex_unlock(&philo->table->m_is_dead), true);
	return (pthread_mutex_unlock(&philo->table->m_is_dead), false);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	philo->last_eat_time = get_timestamp_in_ms();
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->nb_meals_had < philo->data.nb_of_times_to_eat)
	{
		if ((eat(philo) != 0) || (get_is_dead(philo) == true))
			break ;
		if ((ft_sleep(philo) != 0) || (get_is_dead(philo) == true))
			break ;
		if ((think(philo) != 0) || (get_is_dead(philo) == true))
			break ;
	}
	return (NULL);
}
