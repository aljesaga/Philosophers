/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:46:29 by alsanche          #+#    #+#             */
/*   Updated: 2022/07/05 11:35:44 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	philo->time_rest += 5;
	pthread_mutex_lock(&philo->table->fork[philo->l_fork]);
	pthread_mutex_lock(&philo->table->fork[philo->r_fork]);
	print_action(philo, "has take a fork");
	philo->time_rest = 0;
	print_action(philo, "is eating");
	pthread_mutex_unlock(&philo->table->fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->r_fork]);
	philo->time_rest += 5;
}

void	sleeping(t_philo *philo)
{
	philo->time_rest += philo->table->time_to_sleep;
	print_action(philo, "is sleeping");
}

void	thinking(t_philo *philo)
{
	philo->time_rest += philo->table->time_to_sleep;
	print_action(philo, "is thinking");
}
