/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:47:00 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/03 18:34:01 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	time_now(void)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
}

void	its_a_life(t_philo **philo, t_table *table)
{
	while (table->die != 1)
	{
		pthread_mutex_lock(&table->life);
		if (time_now() - philo[0]->last_eat >= (size_t)table->time_to_die)
		{
			table->die = 1;
			pthread_mutex_unlock(&table->life);
			print_action(philo[0], "is die");
			break ;
		}
		pthread_mutex_unlock(&table->life);
		usleep(100);
	}
}

void	print_action(t_philo *philo, char *msn)
{
	pthread_mutex_lock(&philo->print);
	printf("[%lu] %d: %s\n", (time_now() - philo->time_init), philo->name, msn);
	pthread_mutex_unlock(&philo->print);
}
