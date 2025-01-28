/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:56:10 by jcoquet           #+#    #+#             */
/*   Updated: 2024/09/10 08:01:01 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>	
# include <unistd.h>	// usleep
# include <stdlib.h>
# include <pthread.h>	// create, join, destroy
# include <sys/time.h>	// gettimeofday
# include <stdbool.h>
# include <limits.h> // size_max
# include <pthread.h>

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"
# define FILL "we have eaten well"

// COLORS
# define RST "\e[0m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define MAGENTA "\e[1;35m"
# define CYAN "\e[1;35m"
# define WHITE "\e[1;36m"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

struct	s_table;

typedef struct s_data
{
	ssize_t	nb_philos;
	size_t	time_to_eat;
	size_t	time_to_die;
	size_t	time_to_sleep;
	ssize_t	nb_of_times_to_eat;
	size_t	start_time;
}				t_data;

typedef struct s_philo
{
	struct s_table	*table;
	ssize_t			id;
	ssize_t			nb_meals_had;
	size_t			last_eat_time;
	pthread_mutex_t	*left_f;
	bool			left_f_locked;
	pthread_mutex_t	*right_f;
	bool			right_f_locked;
	t_data			data;
	size_t			death_angel_time;
}	t_philo;

typedef struct s_table
{
	ssize_t			nb_philos;
	size_t			time_to_eat;
	size_t			time_to_die;
	ssize_t			time_to_sleep;
	ssize_t			nb_of_times_to_eat;
	int				is_dead;
	pthread_mutex_t	m_is_dead;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*forks;
	pthread_t		*philo_ths;
	t_philo			*philos;
}				t_table;

//actions
void	print_action(t_philo *philo, char *action);
int		eat(t_philo *philo);
int		think(t_philo *philo);
int		ft_sleep(t_philo *philo);
void	thinking(t_philo *philo);
int		take_forks(t_philo *philo);

//error
void	print_usage(void);

//free

void	free_data(t_table *table);

//init
int		init_data(t_table *table);

//parsing
bool	check_input(int ac, char **av);
bool	set_parameters(t_table *table, char **av);

//philo
int		philo_simu(t_table *table);

//routine
bool	get_is_dead(t_philo *philo);
void	*routine(void *arg);
bool	check_death(t_philo *philo);

//utils
ssize_t	ft_atost(char *str);
size_t	get_timestamp_in_ms(void);
void	ft_usleep(size_t sleep_time);
int		handle_1_philo(t_philo *philo);

#endif