/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:47:00 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/12 18:12:52 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_now(void)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
}

void	its_a_life(t_philo **philo, t_table *table)
{
	int	i;
	int	foods;

	i = 0;
	foods = 0;
	while (table->die == 0 && i < table->all_philos)
	{
		pthread_mutex_lock(&table->life);
		if (time_now() - philo[i]->last_eat > table->time_to_die)
		{
			print_action(philo[i], "died", R);
			pthread_mutex_unlock(&table->life);
			table->die = 1;
			break ;
		}
		pthread_mutex_unlock(&table->life);
		if (philo[i]->n_foods == table->n_of_foods)
			if (foods++ > table->all_philos)
				break ;
		i++;
		if (i == table->all_philos)
			i = 0;
	}
	if (table->die != 1)
		table->die = 2;
}

void	print_action(t_philo *philo, char *msn, char *cmyk)
{
	pthread_mutex_lock(&philo->table->print);
	if (philo->table->die != 1)
	{
		printf("%s[%lu]", RESET, (time_now() - philo->table->t_init));
		printf("%s %d: %s%s\n", W, philo->name, cmyk, msn);
	}
	pthread_mutex_unlock(&philo->table->print);
}
