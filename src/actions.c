/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 07:49:38 by jcoquet           #+#    #+#             */
/*   Updated: 2024/09/10 15:32:03 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_action(t_philo *philo, char *action)
{
	size_t	chrono;

	if (!philo || !philo->table)
		return ;
	pthread_mutex_lock(&philo->table->m_print);
	chrono = get_timestamp_in_ms() - philo->data.start_time;
	printf("%zu	%zu	%s\n", chrono, philo->id, action);
	pthread_mutex_unlock(&philo->table->m_print);
}

int	take_forks(t_philo *philo)
{
	if ((check_death(philo)) == true)
		return (0);
	pthread_mutex_lock(philo->right_f);
	philo->right_f_locked = true;
	if ((check_death(philo)) == true)
		return (0);
	pthread_mutex_lock(philo->left_f);
	philo->left_f_locked = true;
	if ((check_death(philo)) == true)
		return (0);
	print_action(philo, TAKE_FORKS);
	return (EXIT_SUCCESS);
}

int	eat(t_philo *philo)
{
	size_t	time_to_eat;

	time_to_eat = philo->data.time_to_eat;
	philo->death_angel_time = (get_timestamp_in_ms() + philo->data.time_to_die) - (philo->data.time_to_eat + philo->data.time_to_sleep);
	if (philo->data.nb_philos == 1)
	{
		handle_1_philo(philo);
		return (EXIT_SUCCESS);
	}

	take_forks(philo);
	if ((check_death(philo)) == true)
		return (0);
	philo->nb_meals_had++;
	philo->last_eat_time = get_timestamp_in_ms();
	print_action(philo, EAT);
	while (((get_timestamp_in_ms() - philo->last_eat_time) < time_to_eat) && check_death(philo) == false)
	{
		if (check_death(philo) == true)
			break ;
		usleep(100);
	}
	pthread_mutex_unlock(philo->right_f);
	philo->right_f_locked = false;
	pthread_mutex_unlock(philo->left_f);
	philo->left_f_locked = false;
	return (EXIT_SUCCESS);
}

int	think(t_philo *philo)
{
	size_t	start;

	start = get_timestamp_in_ms();
	print_action(philo, THINK);
		if ((philo->data.nb_philos % 2) == 0)
		{
			while (get_timestamp_in_ms() - start < (philo->data.time_to_eat - philo->data.time_to_sleep))
			{
				// printf("%sDEBUG 1%s", RED, RST);
				if (check_death(philo) == true)
					break ;
				usleep(500);
			}

		}
		else
		{
			// printf("%sDEBUG 1%s", RED, RST);
			while ((get_timestamp_in_ms() - philo->data.start_time) < philo->data.time_to_eat * 3)
			{
				
				// printf("%sDEBUG 1%s", RED, RST);
				if (check_death(philo) == true)
					break ;
				usleep(1000);
			}
		}
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	ft_sleep(t_philo *philo)
{
	size_t	start;

	start = get_timestamp_in_ms();
	print_action(philo, SLEEP);
	while (((get_timestamp_in_ms() - start) < philo->data.time_to_sleep) && check_death(philo) == false)
	{
		if (check_death(philo) == true)
			break ;
		usleep(500);
	}
	return (EXIT_SUCCESS);
}
