/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:46:29 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/22 20:02:00 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_the_forks(t_philo *philo)
{
	philo->table->total_time += 5;
	if (philo->time_rest + 5 > philo->table->time_to_die)
		return (0);
	philo->time_rest += 5;
	pthread_mutex_lock(&philo->table->fork[philo->l_fork]);
	pthread_mutex_lock(&philo->table->fork[philo->r_fork]);
	printf("[%ld] %d : has take a fork\n",
		philo->table->total_time, philo->name);
	usleep(5);
	return (1);
}

int	eating(t_philo *philo)
{
	if (philo->time_rest + 5 > philo->table->time_to_die)
		return (0);
	philo->time_rest = 0;
	philo->table->total_time += philo->table->time_to_eat;
	printf("[%ld] %d : is eating\n", philo->table->total_time, philo->name);
	usleep(philo->table->time_to_eat);
	return (1);
}

int	put_the_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->r_fork]);
	philo->table->total_time += 5;
	philo->time_rest += 5;
	return (1);
}

int	sleeping(t_philo *philo)
{
	philo->time_rest += philo->table->time_to_sleep;
	if (philo->time_rest + 9 > philo->table->time_to_die)
		return (0);
	philo->table->total_time += philo->table->time_to_sleep;
	printf("[%ld] %d : is sleeping\n", philo->table->total_time, philo->name);
	usleep(philo->table->time_to_sleep);
	return (1);
}

int	thinking(t_philo *philo)
{
	philo->time_rest += philo->table->time_to_sleep;
	if (philo->time_rest + 9 > philo->table->time_to_die)
		return (0);
	philo->table->total_time += philo->table->time_to_sleep;
	printf("[%ld] %d : is thinking\n", philo->table->total_time, philo->name);
	usleep(philo->table->time_to_sleep);
	return (1);
}
