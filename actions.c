/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:46:29 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/03 18:36:05 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	add_time(t_philo *philo, size_t t_add)
{
	size_t	time;

	philo->last_eat += t_add;
	time = time_now();
	while (philo->table->die == 0)
	{
		if (time_now() - time > t_add)
			break ;
		usleep(50);
	}
}

void	actions(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);
	print_action(philo, "has take a fork");
	philo->last_eat = time_now();
	print_action(philo, "is eating");
	add_time(philo, philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	print_action(philo, "is sleeping");
	add_time(philo, philo->table->time_to_sleep);
	print_action(philo, "is thinking");
}

void	*philo_run(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (!philo->name % 2)
		usleep(50);
	while (1)
	{
		pthread_mutex_lock(&philo->table->life);
		if (philo->table->die == 1)
		{
			pthread_mutex_unlock(&philo->table->life);
			break ;
		}
		pthread_mutex_unlock(&philo->table->life);
		if (philo->n_foods == philo->table->n_of_foods)
			break ;
		actions(philo);
	}
	return (NULL);
}
