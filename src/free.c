/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:25:30 by jcoquet           #+#    #+#             */
/*   Updated: 2024/09/05 17:02:46 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_data(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
	}
	pthread_mutex_destroy(&table->m_print);
	pthread_mutex_destroy(&table->m_is_dead);
	free(table->philo_ths);
	free(table->philos);
	free(table->forks);
}
