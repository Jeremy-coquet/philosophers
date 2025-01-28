/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:10:54 by jcoquet           #+#    #+#             */
/*   Updated: 2024/09/05 17:04:56 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	table = malloc(sizeof(t_table));
	if (!table)
		return (EXIT_FAILURE);
	if (!check_input(ac, av))
		return (print_usage(), EXIT_FAILURE);
	if (!set_parameters(table, av))
		return (print_usage(), EXIT_FAILURE);
	if (!philo_simu(table))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
