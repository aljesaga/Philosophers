/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:47:00 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/04 17:41:08 by alsanche         ###   ########lyon.fr   */
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
	size_t	p;
	int		i;

	i = 0;
	while (table->die == 0 && i < table->all_philos)
	{
		if (i == table->all_philos)
			i = 0;
		if (philo[table->all_philos - 1]->n_foods == table->n_of_foods)
			table->die = 1;
		pthread_mutex_lock(&table->life);
		if (time_now() - philo[i]->last_eat > (size_t)table->time_to_die)
		{
			print_action(philo[i], "is die", "\033[1;31m");
			table->die = 1;
			pthread_mutex_unlock(&table->life);
		}
		pthread_mutex_unlock(&table->life);
		i++;
	}
}

void	print_action(t_philo *philo, char *msn, char *cmyk)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%s[%lu] %d: ", cmyk, (time_now() - philo->time_init), philo->name);
	printf("%s%s\n", cmyk, msn);
	pthread_mutex_unlock(&philo->table->print);
}
