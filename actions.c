/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:46:29 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/02 14:10:32 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);
	print_action(philo, "has take a fork");
	philo->last_eat = time_now();
	print_action(philo, "is eating");
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	usleep(100);
}

void	sleeping(t_philo *philo)
{
	philo->last_eat += philo->table->time_to_sleep;
	print_action(philo, "is sleeping");
	usleep(100);
}

void	thinking(t_philo *philo)
{
	philo->last_eat += philo->table->time_to_sleep;
	print_action(philo, "is thinking");
	usleep(100);
}

void	*philo_run(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->name % 2)
		usleep(110);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
