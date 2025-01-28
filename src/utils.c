/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:47:01 by jcoquet           #+#    #+#             */
/*   Updated: 2024/09/10 15:30:37 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

ssize_t	ft_atost(char *str)
{
	ssize_t	result;
	ssize_t	i;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

size_t	get_timestamp_in_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL ) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

// void	ft_usleep(size_t sleep_time)
// {
// 	size_t	start;

// 	start = get_timestamp_in_ms();
// 	while ((get_timestamp_in_ms() - start) < sleep_time)
// 		usleep(500);
// }

int	handle_1_philo(t_philo *philo)
{
	while (get_timestamp_in_ms())
	{
		if (check_death(philo) == true)
			break ;
		usleep(500);
	}
	return (EXIT_SUCCESS);
}
