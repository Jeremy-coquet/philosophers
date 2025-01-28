/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:14:56 by jcoquet           #+#    #+#             */
/*   Updated: 2024/09/05 17:08:56 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_usage(void)
{
	write(2, "[ USAGE ] :\n", 12);
	write(2, "<nb_of_philosophers> (1-200)\n", 29);
	write(2, "<time_to_die> (>60)\n", 20);
	write(2, "<time_to_eat> (>60)\n", 20);
	write(2, "<time_to_sleep> (>60)\n", 22);
	write(2, "[OPTIONAL] <nb_of_times_each_philosopher_must_eat>\n", 51);
}
