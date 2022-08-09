/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:46:29 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/09 13:03:23 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	add_time(t_philo *philo, size_t t_add)
{
	size_t	time;

	time = time_now();
	while (philo->table->die == 0)
	{
		if (time_now() - time >= t_add)
			break ;
	}
}

void	actions(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_action(philo, "has take a fork", "\033[1;33m");
	if (philo->table->all_philos == 1)
	{
		print_action(philo, "is die", "\033[1;31m");
		philo->table->die = 1;
		pthread_mutex_unlock(&philo->fork);
		return ;
	}
	pthread_mutex_lock(&philo->next->fork);
	print_action(philo, "has take a fork", "\033[1;33m");
	print_action(philo, "is eating", "\033[1;32m");
	if (philo->n_foods != -1)
		philo->n_foods++;
	philo->last_eat = time_now();
	add_time(philo, philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	*philo_run(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->name % 2 == 0)
		usleep(100);
	while (philo->table->die != 1)
	{
		if (philo->table->die == 1)
			return (NULL);
		actions(philo);
		if (philo->n_foods == philo->table->n_of_foods)
			return (NULL);
		if (philo->table->die == 1)
			return (NULL);
		print_action(philo, "mis sleeping", "\033[1;36m");
		add_time(philo, philo->table->time_to_sleep);
		if (philo->table->die == 1)
			return (NULL);
		print_action(philo, "is thinking", "\033[1;35m");
	}
	return (NULL);
}
